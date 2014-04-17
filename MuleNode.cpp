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
using std::cout;
using std::endl;

//Process SEND events on MuleNode
void MuleNode::procSend( PacketEvent * event, EventList * elist ) {

  cerr << "[DEBUG] MuleNode::procSend at " << this;
  cerr << ": time is " << event->getTime() << endl;

  //Send events are processed into receive events immediately.

  int indexHere = event->getIndex();
  Node * here = event->currentStop();
  Node * next = event->nextHop();
  int indexNext = event->getIndex();
  cerr << "[DEBUG] Event landed at " << here << " with index " << indexHere << endl;
  cerr << "[DEBUG] Event headed to " << next << " with index " << indexNext << endl;

  //This callback event will let us know the send is finished.
  PacketEvent * callback = new PacketEvent( PACKET_CALLBACK,
                                            event->getTime() + event->size(),
                                            new Route( (Node *)this ), 0 );

  event->setType( PACKET_RECEIVE );
  event->addTime( this->getPropTimeTo( next ) +
		  event->size() );

  cout << "[SIM] MuleNode at " << this << " is SENDING a packet!\n";

  this->busy = true; //The mule is busy once it begins sending.

  elist->insert( (Event*)event );
  elist->insert( (Event*)callback );

}

//Process RECEIVE on MuleNode
void MuleNode::procReceive( PacketEvent * event, EventList * elist,
			 EventList * completedEvents ) {

  cerr << "[DEBUG] MuleNode::procReceive at " << this;
  cerr << ": time is " << event->getTime() << endl;

  if( this->busy ) {

    cerr << "[SIM] Enqueueing event " << event << " on MuleNode at " << this << "!\n";
    //cerr << "[DEBUG] Event " << event << " presents with index " << event->getIndex() << endl;
    //cerr << "[DEBUG] Queue has headPtr " << this->queue->getHeadPtr() << endl;
    this->queue->push( event ); //Push this event onto the mule's queue
    //cerr << "[DEBUG] After the push, has headPtr " << this->queue->getHeadPtr() << endl;
  
  } else {

    //cerr << "[DEBUG] Mule " << this << " is not busy.\n";
    this->procSend( event, elist ); // Dispatch this event as a SEND
                                    //   immediately.
  }

}

//Process CALLBACK on MuleNode
void MuleNode::procCallback( PacketEvent * event, EventList * elist ) {

  cerr << "[DEBUG] MuleNode::procCallback at " << this;
  cerr << ": time is " << event->getTime() << endl;

  if( this->queue->getHeadPtr() ) { // The queue is not empty, so dequeue the next event

    //cerr << "[DEBUG] Queue has headPtr " << this->queue->getHeadPtr() << endl;

    PacketEvent * qEvent = this->queue->pop();

    //cerr << "[DEBUG] After the pop, headPtr is " << this->queue->getHeadPtr() << endl;

    qEvent->addTime( event->getTime() - qEvent->getTime() ); //Account for time waiting.
    cerr << "[SIM] Dequeueing event " << qEvent << " from MuleNode at " << this << "!\n";
    //cerr << "[DEBUG] Event " << qEvent << " presents with index " << qEvent->getIndex() << endl;
    this->procSend( qEvent, elist ); //Dispatch this event immediately
  
  } else {

    //cerr << "[DEBUG] The queue for Mule " << this << " is no longer full, and is no longer busy.\n";
    this->busy = false;
  
  }

  delete event;

}
