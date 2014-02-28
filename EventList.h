/* CS2303 - Lab 5 - EventList.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares our implementation of an EventList.
 */

#ifndef EVENTLIST_H
#define EVENTLIST_H

#include "Event.h"

class ELNode {

 protected:
  ELNode * nextPtr;
  Event * ev;

 public:
  ELNode( Event * initEvent );
  Event * get();
  ELNode * insert( Event * newEvent );
  ELNode * getNextPtr();
  void setNextPtr( ELNode * newNextPtr );

};

class EventList {

 protected:
  ELNode * rootNode;

 public:
  EventList();
  EventList( Event * initEvent );
  Event * first();
  Event * next();
  void insert( Event * newEvent );

};

#endif
