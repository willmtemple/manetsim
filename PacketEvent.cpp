/* CS2303 - Lab 5 - PacketEvent.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a subclass of Event.
 */

#include "PacketEvent.h"

#include "Node.h"

//Constructor for packetEvent
PacketEvent::PacketEvent( PType iType, int evTime,
			  Route * routeInfo, int pSize ) {

  this->setTime( evTime );

  this->type = iType;
  this->routeInfo = routeInfo;
  this->routeIndex = 0;
  this->pSize = pSize;

}

//getter for type
PType PacketEvent::getType() {

  return this->type;

}

//setter for type
void PacketEvent::setType( PType newType ) {

  this->type = newType;

}

//Get the current node
Node * PacketEvent::currentStop() {

  return this->routeInfo->getAt( routeIndex );

}

//Getter for index
int PacketEvent::getIndex() {

  return routeIndex;

}

//Get node index of nextHop, then increment index
Node * PacketEvent::nextHop() {

  routeIndex++;

  return this->routeInfo->getAt( routeIndex );

}

//Add an amout of time to totalTime
void PacketEvent::addTime( int time ) {

  this->increaseTime( time );
  this->totalTime += time;

}

//Return the route
Route * PacketEvent::getRoute() {

  return this->routeInfo;

}

//Getter for pSize
int PacketEvent::size() {

  return this->pSize;

}
