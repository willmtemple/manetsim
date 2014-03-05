/* CS2303 - Program 5 - SenderNode.h
 * Authors:                                                                   
 *   William M. Temple                                                         
 *   Sonam T. Sherpa                                                           
 *                                                                             
 * This file defines the implementation of a SenderNode.                      
 */

#include "SenderNode.h"
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

//Process SEND events on SenderNode
void SenderNode::procSend( PacketEvent * event, EventList * elist ) {

  cerr << "[DEBUG] procSend on SENDER " << this;
  cerr << ", time is " << event->getTime() << endl;

  int timeTo = packSize + getPropTimeTo( event->nextHop() );

  cerr << "[DEBUG] this SEND will take " << timeTo << endl;

  //Declare and insert a callback that will control when the next SEND
  //  is dispatched from this node.
  PacketEvent * callback = new PacketEvent( PACKET_CALLBACK,
					     event->getTime() + this->packSize,
					     new Route( (Node *)this ), 0 );

  //Process SEND events into RECEIVE events immediately.
  event->setType( PACKET_RECEIVE );
  event->addTime( timeTo );
  
  cout << "[SIM] " << this << " is SENDING a packet!\n";

  //We now need to send one less packet.
  packets--;
  elist->insert( (Event*)event );

  elist->insert( (Event*)callback );

}

//This should never happen. A SENDER can never RECEIVE.
void SenderNode::procReceive( PacketEvent * event, EventList * elist,
			 EventList * completedEvents ) {

  std::cerr << "[ERROR] Recieve event targeted at SenderNode.\n";
  std::cerr << event << " " << event->getIndex() << endl;
  std::exit( 1 );

}

//Process CALLBACK on SenderNode
void SenderNode::procCallback( PacketEvent * event, EventList * elist ) {

  cerr << "[DEBUG] procCallback on SENDER " << this;
  cerr << ", time is " << event->getTime() << endl;

  if( packets > 0 ) { //We still have packets to send.

    cerr << "[DEBUG] procCallback: Callback IS dispatching new event.\n";

    //Dispatch a new SEND into a RECEIVE event immediately.
    this->procSend( new PacketEvent( PACKET_SEND, event->getTime(),
				     this->myRoute, this->packSize ), elist );
  
  }

  delete event;

}

//Setter for Route
void SenderNode::setRoute( Route * newRoute ) {

  this->myRoute = newRoute;

}
