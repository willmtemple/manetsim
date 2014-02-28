/* CS2303 - Lab 5 - global.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file is a global include for all Lab/Program 5 driver files.
 */

#ifndef GLOBAL_H
#define GLOBAL_H

//INCLUDES

#include <iostream>

#include "PacketQueue.h"
#include "EventList.h"
#include "Node.h"

//PROTOTYPES

void eventDispatch( EventList * elist, PacketEvent * event,
		    RouteNode * routeNodes[] );

#endif
