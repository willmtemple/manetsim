/* CS2303 - Lab 5 - PacketEvent.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a subclass of Event.
 */

#include "PacketEvent.h"

//Constructor for packetEvent
PacketEvent::PacketEvent( PType iType, int evTime, Route * routeInfo ) {

  this->setTime( evTime );

  this->type = iType;
  this->routeInfo = routeInfo;
  this->routeIndex = 0;

}

//getter for type
PType PacketEvent::getType() {

  return this->type;

}

//setter for type
void PacketEvent::setType( PType newType ) {

  this->type = newType;

}

//Get node index of nextHop, then increment index
int PacketEvent::nextHop() {

  return this->routeInfo->getAt( (this->routeIndex)++ )->getID();

}

//Add an amout of time to totalTime
void PacketEvent::addTime( int time ) {

  this->totalTime += time;

}

//Return the route
Route * PacketEvent::getRoute() {

  return this->routeInfo;

}
