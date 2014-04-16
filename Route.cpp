/* CS2303 - Lab 5 - Route.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a Routing LinkedList.
 */

#include "Route.h"

#include <cassert>

//Easy init constructor
Route::Route( Node * iNode ) {

  this->node = iNode;
  this->nextHop = NULL;

}

//Setter for nextHop
void Route::setNext( Route * nextHop ) {

  this->nextHop = nextHop;

}

//Getter for nextHop
Route * Route::getNext() {

  return this->nextHop;

}

//Recursive "find at index"
Node * Route::getAt( int index ) {

  if( index <= 0 ) return this->node;
  if( this->nextHop == NULL ) return NULL;

  return this->nextHop->getAt( index - 1 );

}

//Put another node on the route.
void Route::add( Route * next ) {

  assert( next != this );

  if( this->node == NULL ) {

    this->node = next->get();
    delete next;
    return;

  }

  if( this->nextHop == NULL )
    this->nextHop = next;
  else
    this->nextHop->add( next );

}

//Get the id
Node * Route::get() {

  return this->node;

}
