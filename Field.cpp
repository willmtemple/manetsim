/* CS2303 - Program 5 - Field.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines functions associated with maintaining the MANET map.
 */

#include "Field.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

//Introducing the world's largest constructor. Does a lot of things.
Field::Field( int senders, int mules, int receivers,
	      int dim, EventList * elist ) {

  //First, initialize the arrays.

  this->nodes = new Node * [senders + mules + receivers];
  this->senders = new SenderNode * [dim];
  this->receivers = new ReceiverNode * [dim] ;
  this->field = new Node ** [dim];

  this->nodeCnt = senders+mules+receivers;
  this->muleCnt = mules;
  this->sndCnt = senders;
  this->rcvCnt = receivers;
  this->dim = dim;

  //Need a 2d array of Node pointers.
  for( int i = 0; i < dim; i++ )
    this->field[i] = new Node * [dim];

  int i = 0;

  //Second, create new mules.
  for( i = senders; i < senders + mules; i++ ) {

    int x,y = 0;

    do {
      x = rand() % dim;
      y = rand() % dim;
    } while ( field[x][y] != NULL );
    
    nodes[i] = new MuleNode( x, y, i, i % 4 );
    field[x][y] = nodes[i];

  }

  //Third, create new Receivers.
  //  Note, i will be the first index in the RECEIVER range when this is run
  for( i = senders+mules; i < senders+mules+receivers; i++ ) {

    int y = 0;

    do {

      y = rand() % dim;

    } while ( this->receivers[y] != NULL );

    nodes[i] = new ReceiverNode( dim, y, i );
    this->receivers[y] = (ReceiverNode *)nodes[i];

  }

  //Finally, the senders, which are obnoxiously complicated

  string scriptLine;

  int sId = 0;
  int sATime = 0;
  int sPackets = 0;
  int sPackSize = 0;

  //This while will exit at the end of the file.
  while( getline( cin, scriptLine ) ) {

    cerr << "[DEBUG] Field: got line" << scriptLine << endl;

    int pIndex = 0; //This signifies where we are on the current line.
    int pVal = 0;   //This value is that which we are considering

    //Came up with this bit of stringstream coolness
    std::stringstream scriptStream ( scriptLine );

    //Pick a y-location for this node
    int y = 0;
    do {
      y = rand() % dim;
    } while ( this->senders[y] != NULL );

    //This while will exit at the end of each line
    while( scriptStream >> pVal ) {

      cerr << "[DEBUG] Field: Line index " << pIndex << " is " << pVal << endl;

      //Behave differently based on pIndex
      switch( pIndex++ ) {

      case 0: // This int determines the id of the node
	      sId = pVal;
	      break;

      case 1: // This int determines the arrival time of the node
	      sATime = pVal;
	      break;
	
      case 2: // This int determines the number of packets sent
	      sPackets = pVal;
	      break;

      case 3: //This int determines the packet size
	      sPackSize = pVal;
	      break;

      case 4: //This int gives us number of  route nodes
	
	      //Create the new sender node.
	      SenderNode * sNode = new SenderNode( -1, y, sId, sPackets, NULL, sPackSize );
	
	      cerr << "[DEBUG] Field: created new Sender Node! " << sNode << endl;

	      Route * newRoute = new Route( sNode );

	      cerr << "[DEBUG] SNODE ID IS " << sNode << endl;

	      int routeNodeID = 0;
	      //We don't really care how many nodes are in the route. We'll add them
	      //  all.
	      while( scriptStream >> routeNodeID ) {
	        cerr << "[DEBUG] Adding " << routeNodeID << endl;
	        if( routeNodeID !=  sId ) //Took care of this with constructor.
	          newRoute->add( new Route( nodes[routeNodeID - 1] ) );
	      }

	      sNode->setRoute( newRoute );

	      //At long last, add the sender to its rightful place.
	      //  But be safe and die if that spot's taken.
	      if( nodes[sId - 1] != NULL ) {

	        cerr << "[ERROR] Attempted to overwrite node.\n";
	        std::exit(1);

	      }
	
	      nodes[sId - 1] = sNode;
	      this->senders[y] = sNode;

	      //And push its first event onto the eventlist.
	      elist->insert( new PacketEvent( PACKET_SEND, sATime, newRoute,
				                                sPackSize ) );
	
	      break;

      }

    }

  }

}

//Getter by xy position
Node * Field::getPos(int x, int y) {

  return this->field[x][y];

}

//Getter by index
Node * Field::getInd( int index ) {

  return this->nodes[index];

}

//Move all the mules on the field
void Field::moveMules() {

  for( int i = sndCnt; i < sndCnt+muleCnt; i ++ ) {

    MuleNode * curMule = (MuleNode *)nodes[i];
    cerr << "[DEBUG] moveMules: moving mule " << curMule << endl;
    int tX = curMule->x;
    int tY = curMule->y;
    int iX = tX;
    int iY = tY;

    cerr << "[DEBUG] moveMules:  its coordinates are " << iX << " " << iY << endl;

    //Easy expression. Read "While the space being considered is
    //  invalid."
    while( field[tX][tY] != NULL ) {

      switch( curMule->getDir() ) {

      case NORTH:
	if( tY <= 0 ) {
	  curMule->setDir( SOUTH );
	  break;
	}
	tY--;
	break;

      case SOUTH:
	if( tY >= (dim - 1) ) {
          curMule->setDir( NORTH );
	  break;
        }
	tY++;
	break;

      case EAST:
	if( tX >= (dim - 1) ) {
          curMule->setDir( WEST );
	  break;
        }
	tX++;
	break;

      case WEST:
	if( tX <= 0 ) {
          curMule->setDir( EAST );
	  break;
        }
	tX--;
	break;

      }

    }

    curMule->x = tX;
    curMule->y = tY;

    field[iX][iY] = NULL;
    field[tX][tY] = curMule;

  }

}

//Simply print the field with Sources West and Receivers East
void Field::draw() {

  for( int i = 0; i < dim; i++ ) {

    cout << (this->senders[i]?"[S]":"[0]");

    for( int j = 0; j < dim; j++ ) {

      cout << (this->field[i][j]?"[M]":"[ ]");

    }

    cout << (this->receivers[i]?"[R]":"[0]") << endl;

  }

}

//Print all items on the nodes table
void Field::prnTable() {

  for( int i = 0; i < nodeCnt; i++ ) {

    cerr << "[DEBUG] prnTable: " << i << " " << nodes[i]->x << " " << nodes[i]->y << endl; 

  }

}
