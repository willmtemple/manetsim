/* CS2303 - Lab 5 - EventList.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines functions associated with the EventList and ELNode
 *   classes.
 */

#include "EventList.h"

#define NULL 0

//Constructor with an initial event.
ELNode::ELNode( Event * initEvent ) {

  this->nextPtr = NULL;
  this->ev = initEvent;

}

//Get a handle to this Node's Event.
Event * ELNode::get() {

  return this->ev;

}

//nextPtr setter
void ELNode::setNextPtr( ELNode * newNextPtr ) {

  this->nextPtr = newNextPtr;

}

//nextPtr getter
ELNode * ELNode::getNextPtr() {

  return this->nextPtr;

}

//Put a new event on the list
ELNode * ELNode::insert( Event * newEvent ) {

  //First case, we need to add before this node.
  if( newEvent->getTime() < this->ev->getTime() ) {

    //Need a new node to contain newEvent
    ELNode * newNode = new ELNode( newEvent );

    //Set it's next pointer to this, then return newEvent 
    newNode->setNextPtr( this );
    return newNode;

  } else if( this->getNextPtr() == NULL ) {

    //In this case, we are the last item, so we need to add directly to the end

    ELNode * newNode = new ELNode( newEvent );
    this->setNextPtr( newNode );
    return this;

  } else { //Else add after this, which is recursion

    //Set the next pointer equal to the result of insertion of
    //  newEvent on the next item in the list.
    this->setNextPtr( this->getNextPtr()->insert( newEvent ) );

    //Parent nodes rely on setting the next pointer to the value
    //  returned here. Honor that contract.
    return this;

  }

}

//Default EL constructor
EventList::EventList() {

  this->rootNode = NULL;

}

//EL constructor with initial event
EventList::EventList( Event * initEvent ) {

  this->rootNode = new ELNode( initEvent );

}

//Return the first event without removing it.
Event *  EventList::first() {

  if( this->rootNode == NULL ) return NULL;

  return this->rootNode->get();

}

//Remove the first event, then return it
Event * EventList::next() {

  if( this->rootNode == NULL ) return NULL;

  Event * ret = this->rootNode->get();

  this->rootNode = this->rootNode->getNextPtr();

  return ret;

}

//EventList facade method that will init if NULL and
//  insert into list if not.
void EventList::insert( Event * newEvent ) {

  if( this->rootNode == NULL ) {

    this->rootNode = new ELNode( newEvent );
    return;

  }

  this->rootNode = this->rootNode->insert( newEvent );

}

//Getter for rootNode
ELNode * EventList::getRootNode() {

  return rootNode;

}
