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

typedef enum {PACKET_SEND, PACKET_SENT, PACKET_RECEIVE} PType;

class PacketEvent: public Event {

 protected:
  PType type;
  int routeIndex;
  Route * routeInfo;
  int totalTime;

 public:
  PacketEvent( PType iType, int evTime, Route * iRouteInfo );
  PType getType();
  void setType( PType newType );
  int nextHop();
  void addTime( int time );

};

#endif
