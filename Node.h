/* CS2303 - Lab 5 - Node.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares a parent Node class.
 */

#ifndef NODE_H
#define NODE_H

#include "PacketEvent.h"
#include "EventList.h"
#include "PacketQueue.h"

class Node {

 public:
  int x, y, id;
  virtual ~Node() {}
  Node( int x, int y, int id );
  void setLoc( int x, int y );
  int getPropTimeTo( Node * otherNode );
  virtual void procSend( PacketEvent * event, EventList * elist ) = 0;
  virtual void procReceive( PacketEvent * event, EventList * elist,
			    EventList * completedEvents ) = 0;
  virtual void procCallback( PacketEvent * event, EventList * elist ) = 0;

};

#endif
