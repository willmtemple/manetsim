/* CS2303 - Lab 5 - main.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the driver program for Lab 5.
 */

#include "global.h"

using namespace std;

//Some STL features that we use frequently.
using std::cerr;
using std::endl;
using std::cout;

//This debugging function prints the EventList. It is large.
void prnEList(ELNode * elnode) {

  if( elnode == NULL ) return;

  cerr << "ADDRESS TIME TYPE" << endl;
  cerr << elnode->get() << " " << elnode->get()->getTime();
  cerr << " " << ((PacketEvent *)elnode->get())->getType() << endl;
  
  prnEList( elnode->getNextPtr() );

}

//This function was appropriately named.
void printUsageAndDie() {

  cerr << "[ERROR] Usage:" << endl;
  cerr << "\tmanetsim [SOURCES] [RECEIVERS] [MULES] [DIM]" << endl;
  cerr << "\t[SOURCES] indicates the number of SENDER nodes\n";
  cerr << "\t[RECEIVERS] indicates the number of RECEIVER nodes\n";
  cerr << "\t[MULES] indicates the number of MULE nodes\n";
  cerr << "\t[DIM] indicates the length and width of the square field\n";

  std::exit( 1 );

}

//EP
int main( int argc, char* argv[] ) {

  if( argc != 5 ) //Invalid CLI
    printUsageAndDie();

  cerr << "[DEBUG] main: srand()\n";

  srand( time( NULL ) );

  //Pull info from CLI args array
  int senders   = atoi( argv[1] );
  int receivers = atoi( argv[2] );
  int mules     = atoi( argv[3] );
  int dim       = atoi( argv[4] );

  //Our main event structures
  EventList * elist = new EventList();
  EventList * completedEvents = new EventList();

  cerr << "[DEBUG] main: Creating MANET field.\n";

  //Our MANET field. The input from cin is taken within this constructor
  Field * manetField = new Field( senders, mules, receivers, dim, elist );
  
  manetField->draw();

  //Put the initial move event on the list.
  elist->insert( (Event *)( new PacketEvent( MOVE, 10, 0, 0 ) ) );

  //The main driver
  while ( elist->first() != NULL ) {

    //prnEList( elist->getRootNode() );

    PacketEvent * pEv = (PacketEvent *)elist->next();
    cerr << "[DEBUG] main: have pEv " << pEv << endl;

    switch( pEv->getType() ) { //This switch dispatches to the correct function
                               //  in the node members.
    case PACKET_SEND:
      pEv->currentStop()->procSend( pEv, elist );
      break;

    case PACKET_CALLBACK:
      pEv->currentStop()->procCallback( pEv, elist );
      break;
      
    case PACKET_RECEIVE:
      pEv->currentStop()->procReceive( pEv, elist, completedEvents );

    case MOVE: //Takes care of moving the mules.
      manetField->moveMules();
      manetField->draw();
      //If the eventlist isn't now empty, then we need to push on another MOVE
      if(elist->first() != NULL) {

	pEv->addTime(10);
	elist->insert(pEv);

      }
      break;

    }
    
  }

  cout << "[SIM] Finished!\n";

}
