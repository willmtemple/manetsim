/* CS2303 - Lab 5 - Route.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the implementation of a data structure
 *   for MANET routes.
 */

#ifndef ROUTE_H
#define ROUTE_H

class Route {

 protected:
  int id;
  Route * nextHop;

 public:
  Route( int id );
  void setNext( Route * nextHop );
  int getID();
  Route * getNext();
  Route * getAt( int index );
  void add( Route * next );

};

#endif
