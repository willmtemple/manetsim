/* CS2303 - Lab 5 - eventDispatch.cpp
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file defines the eventDispatch driver.
 */

#include "global.h"

using std::cout;
using std::endl;

void eventDispatch( EventList * elist, PacketEvent * event,
		    RouteNode * routeNodes[] ) {

  switch( event->type ) {

    //If packet is SEND, then find the sender node, and 
  case PACKET_SEND: 
    routeNodes[ event->nextHop() ]->procSend( event );
    break;

    /* case PACKET_SENT:
       break;*/

  case PACKET_RECEIVE:
    routeNodes[ event->nextHop() ]->procRcv( event );
    break;

  }

  return;

}
