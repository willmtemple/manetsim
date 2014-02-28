/* CS2303 - Lab 5 - main.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the driver program for Lab 5.
 */

#include "global.h"

//Some STL features that we use frequently.
using std::cerr;
using std::endl;
using std::cout;

void populateEventList( EventList * elist ) {

  Route * r1 = new Route( 0 );
  Route * r2 = new Route( 1 );

  r1->add( new Route( 2 ) );
  r2->add( new Route( 2 ) );
  r1->add( new Route( 3 ) );
  r2->add( new Route( 3 ) );
  r1->add( new Route( 4 ) );
  r2->add( new Route( 4 ) );

  PacketEvent * pe1 = new PacketEvent( PACKET_SEND, 0, r1 );
  PacketEvent * pe2 = new PacketEvent( PACKET_SEND, 3, r2 );

  elist->insert( (Event *)pe1 );
  elist->insert( (Event *)pe2 );

}

//EP
int main( int argc, char* argv[] ) {

  if( argc != 1 ) { //If the program usage is incorrect, print an error.

    cerr << "[ERROR] Program usage incorrect. Continuing." << endl;
    //Program can continue as normal, as no info is needed from cli

  }

  

  EventList * elist = new EventList();

  populateEventList( elist );

  //The main driver
  while ( elist->first() != NULL ) {

    //Take the next event off the eventList and dispatch it.
    eventDispatch( elist, (PacketEvent *) elist->next(), routeNodes );

  }

  cout << "[SIM] Finished!\n";

}
