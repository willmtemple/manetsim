/* CS2303 - Program 5 - MuleNode.h
 * Authors:                                                                   
 *   William M. Temple                                                         
 *   Sonam T. Sherpa                                                           
 *                                                                             
 * This file defines the implementation of a MuleNode.                      
 */

#include "MuleNode.h"
#include <iostream>

using std::cerr;
using std::endl;

//Process SEND events on MuleNode
void MuleNode::procSend( PacketEvent * event, EventList * elist ) {

  cerr << "[DEBUG] procSend called on MULE " << this;
  cerr << ", time is " << event->getTime() << endl;

  //Send events are processed into receive events immediately.

  //This callback event will let us know the send is finished.
  PacketEvent * callback = new PacketEvent( PACKET_CALLBACK,
                                            event->getTime() + event->size(),
                                            new Route( (Node *)this ), 0 );

  event->setType( PACKET_RECEIVE );
  event->addTime( this->getPropTimeTo( event->nextHop() ) +
		  event->size() );

  this->busy = true; //The mule is busy once it begins sending.

  elist->insert( (Event*)event );
  elist->insert( (Event*)callback );

}

//Process RECEIVE on MuleNode
void MuleNode::procReceive( PacketEvent * event, EventList * elist,
			 EventList * completedEvents ) {

  if( this->busy )
    this->queue->push( event ); //Push this event onto the mule's queue
  else 
    this->procSend( event, elist ); // Dispatch this event as a SEND
                                    //   immediately.
}

//Process CALLBACK on MuleNode
void MuleNode::procCallback( PacketEvent * event, EventList * elist ) {

  if( this->queue->getHeadPtr() )
    this->procSend( this->queue->pop(), elist );
  else 
    this->busy = false;

  delete event;

}
