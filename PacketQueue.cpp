/* CS2303 - Lab 5 - PacketQueue.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the implementation of a PacketQueue.
 */

#include "PacketQueue.h"

//Easy init constructor
PQNode::PQNode( PacketEvent * initEvent ){

  this->nextPtr = NULL;
  this->packet = initEvent;

}

//Getter for the packet
PacketEvent * PQNode::get() {

  return this->packet;

}

//Setter for the packet
void PQNode::set( PacketEvent * newEvent ) {

  this->packet = newEvent;

}

//Getter for nextPtr
PQNode * PQNode::getNextPtr() {

  return this->nextPtr;

}

//Setter for nextPtr
void PQNode::setNextPtr( PQNode * newPtr ) {

  this->nextPtr = newPtr;

}

//Default contstructor
PacketQueue::PacketQueue() {

  this->headPtr = NULL;
  this->tailPtr = NULL;

}

//Easy init constructor
PacketQueue::PacketQueue( PacketEvent * initEvent ) {

  this->headPtr = new PQNode( initEvent );
  this->tailPtr = this->headPtr;

}

//Push a new event onto the queue
void PacketQueue::push( PacketEvent * newEvent ) {

  if( this->tailPtr == NULL ) {

    this->headPtr = new PQNode( newEvent );
    this->tailPtr = this->headPtr;

  }

  this->tailPtr->setNextPtr( new PQNode( newEvent ) );
  this->tailPtr = this->tailPtr->getNextPtr();

}

//Pop the top event from the queue
PacketEvent * PacketQueue::pop() {

  if( this->headPtr == NULL ) return NULL;

  PacketEvent * ret = this->headPtr->get();

  if( this->headPtr == this->tailPtr ) {

    delete this->headPtr;
    this->headPtr = NULL;
    this->tailPtr = NULL;

  } else {

    PQNode * del = this->headPtr;
    this->headPtr = del->getNextPtr();
    delete del;

  }
  
  return ret;

}

PQNode * PacketQueue::getHeadPtr() {

  return this->headPtr;

}
