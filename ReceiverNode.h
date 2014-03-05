/* CS2303 - Program 5 - SenderNode.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the implementation of a SenderNode.
 */

#include "Node.h"

//Receiver nodes are actually really boring.

class ReceiverNode : public Node {

 private:
  typedef Node super;

 public:
  ReceiverNode( int x, int y, int id )
    : super( x, y, id ) { }
    void procSend( PacketEvent * event, EventList * elist );
    void procReceive( PacketEvent * event, EventList * elist,
		      EventList * completedEvents );
    void procCallback( PacketEvent * event, EventList * elist );

};
