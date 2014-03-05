/* CS2303 - Program 5 - SenderNode.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the implementation of a SenderNode.
 */

#include "Node.h"

class MuleNode : public Node {

 private:
  typedef Node super;
  PacketQueue * queue;
  bool busy;
  int dir;

 public:
  MuleNode( int x, int y, int id, int dir)
    : super( x, y, id ) { 
    this->queue = new PacketQueue();
    this->busy = false;
    this->dir = dir;
  }

    void procSend( PacketEvent * event, EventList * elist );
    void procReceive( PacketEvent * event, EventList * elist,
		      EventList * completedEvents );
    void procCallback( PacketEvent * event, EventList * elist );
    int getDir() { return dir; }
    void setDir( int newDir ) { this->dir = newDir; }

};
