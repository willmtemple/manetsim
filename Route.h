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

#include <cstdlib>

class Node;

class Route {

 protected:
  Node* node;
  Route * nextHop;

 public:
  Route() { node = NULL; nextHop = NULL; }
  Route( Node * iNode );
  void setNext( Route * nextHop );
  Node * get();
  Route * getNext();
  Node * getAt( int index );
  void add( Route * next );

};

#endif
