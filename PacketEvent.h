/* CS2303 - Lab 5 - PacketEvent.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines an extension of Event which contains packet information.
 */

#ifndef PACKETEVENT_H
#define PACKETEVENT_H

#include "Event.h"
#include "Route.h"

typedef enum {PACKET_SEND, PACKET_CALLBACK, PACKET_RECEIVE, MOVE} PType;

class Node;

class PacketEvent: public Event {

 private:
  PType type;
  int routeIndex;
  Route * routeInfo;
  int totalTime;
  int pSize;

 public:
  PacketEvent( PType iType, int evTime, Route * iRouteInfo, int pSize );
  PType getType();
  int getIndex();
  int size();
  void setType( PType newType );
  Node * currentStop();
  Node * nextHop();
  void addTime( int time );
  Route * getRoute();

};

#endif
