/* CS2303 - Lab 5 - Node.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a RouteNode class.
 */

//Easy init constructor
RouteNode::RouteNode( RNType t, int x, int y, int propTime, int transTime ) {

  this->type = t;
  this->x = x;
  this->y = y;
  this->propTime = propTime;
  this->transTime = transTime;

}

//Set the location of the Node
void RouteNode::setLoc( int x, int y ) {

  this->x = x;
  this->y = y;

}

//Set the type of the node
void RouteNode::setType( RNType t ) {

  this->type = t;

}

//Getters and setters
int RouteNode::getTransTime() { return this->transTime; }

void RouteNode::setTransTime( int newTransTime ) {

  this->transTime = newTransTime;

}

int RouteNode::getPropTime() { return this->propTime; }

void RouteNode::setPropTime( int newPropTime ) {

  this->propTime = newPropTime;

}

//Meaty functions that do the event processing
void RouteNode::procSend( PacketEvent * event, EventList * elist ) {

  //Behave differently according to node type
  switch( this->type ) {

  case RECEIVER: //This will never happen
    return;

  default: //If the node is not a receiver, then create a new send event,
           //  and then also transmute this event to a receive event
    event->setType( PACKET_RECEIVE );
    event->addTime( this->propTime + this->transTime );
    event->setTime( event->getTime() + this->propTime + this->transTime );
    elist->insert( (Event *)event );
    if( this->packetCount < 100 )
      elist->insert( (Event *) new PacketEvent( PACKET_SEND,
						event->getTime() + this->transTime,
						event->getRoute() ) );
    break;

  }

}

//process recieve events
void procRcv( event
