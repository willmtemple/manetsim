/* CS2303 - Program 5 - SenderNode.h
 * Authors:                                                                   
 *   William M. Temple                                                         
 *   Sonam T. Sherpa                                                           
 *                                                                             
 * This file defines the implementation of a SenderNode.                      
 */

#include "ReceiverNode.h"
#include <iostream>

//Process RECEIVE events on SenderNode
void ReceiverNode::procReceive( PacketEvent * event, EventList * elist,
			 EventList * completedEvents ) {

  //Event has reached its destination (hopefully).
  //  Store it for statistical analysis.
  completedEvents->insert( event );
  
}

//This should never happen. No SEND on RECEIVER.
void ReceiverNode::procSend( PacketEvent * event, EventList * elist ) {

  std::cerr << "[ERROR] Send event targeted at ReceiverNode.\n";
  std::exit( 1 );

}

//This should never happen. No SEND to generate CALLBACK.
void ReceiverNode::procCallback( PacketEvent * event, EventList * elist ) {

  std::cerr << "[ERROR] Callback triggered on ReceiverNode.\n";
  std::exit( 1 );

}
