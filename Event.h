/* CS2303 - Lab 5 - Event.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines an Event class.
 */

#ifndef EVENT_H
#define EVENT_H

class Event {

 protected:
  int eventTime;

 public:
  int getTime() { return eventTime; }
  void setTime( int newTime ) { this->eventTime = newTime; }

};

#endif
