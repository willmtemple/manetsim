/* CS2303 - Lab 5 - Route.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a Routing LinkedList.
 */

#include "Route.h"

#define NULL 0

//Easy init constructor
Route::Route( int id ) {

  this->id = id;
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
Route * Route::getAt( int index ) {

  if( index <= 0 ) return this;
  if( this->nextHop == NULL ) return NULL;

  return this->nextHop->getAt( index - 1 );

}

//Put another node on the route.
void Route::add( Route * next ) {

  if( this->nextHop == NULL ) {

    this->nextHop = next;

  } else {

    this->nextHop->add( next );

  }

}

//Get the id
int getID() {

  return this->id;

}
