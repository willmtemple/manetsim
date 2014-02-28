/* CS2303 - Lab 5 - Node.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares a parent Node class.
 */

#ifndef ROUTENODE_H
#define ROUTENODE_H

#include "PacketEvent.h"
#include "EventList.h"

typedef enum {SENDER, MULE, RECEIVER} RNType;

class RouteNode {

 private:
  RNType type;
  int x, y;
  int propTime;
  int transTime;
  int packetCount;
  PacketQueue pQueue;

 public:
  RouteNode( RNType t, int x, int y, int propTime, int transTime )
  void setLoc( int x, int y );
  void setType( RNType t );
  int getTransTime();
  void setTransTime( int newTransTime );
  int getPropTime();
  void setPropTime( int newPropTime );
  void procSend( PacketEvent * event );
  void procRcv( PacketEvent * event );

};

#endif
