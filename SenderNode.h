/* CS2303 - Program 5 - SenderNode.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the implementation of a SenderNode.
 */

#include "Node.h"

class SenderNode : public Node {

 private:
  typedef Node super;
  int packets;
  int packSize;
  Route * myRoute;

 public:
  SenderNode( int x, int y, int id, int packets,
	      Route * myRoute, int packSize )
    : super( x, y, id ) {

    this->packets = packets;
    this->myRoute = myRoute;
    this->packSize = packSize;

  }
    void setRoute ( Route * newRoute );
    void procSend( PacketEvent * event, EventList * elist );
    void procReceive( PacketEvent * event, EventList * elist,
			      EventList * completedEvents );
    void procCallback( PacketEvent * event, EventList * elist );

};
