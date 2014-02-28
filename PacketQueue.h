/* CS2303 - Lab 5 - PacketQueue.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the implementation of a queue of PacketEvents.
 */

#ifndef PACKETQUEUE_H
#define PACKETQUEUE_H

#include "PacketEvent.h"

class PQNode {

 protected:
  PacketEvent * packet;
  PQNode * nextPtr;

 public:
  PQNode( PacketEvent * initEvent );
  PacketEvent * get();
  void set( PacketEvent * newEvent );
  PQNode * getNextPtr();
  void setNextPtr( PQNode * newPtr );

};

class PacketQueue {

 protected:
  PQNode * headPtr;
  PQNode * tailPtr;

 public:
  PacketQueue();
  PacketQueue( PacketEvent * initEvent );
  PQNode * getHeadPtr();
  void push( PacketEvent * newEvent );
  PacketEvent * pop();

};

#endif
