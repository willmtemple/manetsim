/* CS2303 - Lab 5 - Node.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a RouteNode class.
 */

#include <cmath>
#include <iostream>
#include "Node.h"

using std::cerr;
using std::endl;

double dist( int x1, int y1, int x2, int y2 ) {

  return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

}

//Easy init constructor
Node::Node( int x, int y, int id ) {

  this->x = x;
  this->y = y;
  this->id = id;

}

//Set the location of the Node
void Node::setLoc( int x, int y ) {

  this->x = x;
  this->y = y;

}

//Calculate the propagation time to another node
int Node::getPropTimeTo( Node * otherNode ) {

  cerr << "[DEBUG] calculating prop time between ";
  cerr << x << " " << y << " " << otherNode->x << " " << otherNode->y << endl;

  return (int)ceil( log2( dist( x, y, otherNode->x, otherNode->y ) ) );

}
