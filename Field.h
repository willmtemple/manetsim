/* CS2303 - Program 5 - Field.h
 * Authors:
 *   William M. Temple
 *   Sonam T. Sherpa
 *
 * This file declares the structure which controls the MANET field.
 */

#include "Node.h"
#include "MuleNode.h"
#include "SenderNode.h"
#include "ReceiverNode.h"

enum {NORTH, SOUTH, EAST, WEST};

class Field {

 private:
  int nodeCnt, sndCnt, rcvCnt, muleCnt, dim;
  Node ** nodes;
  SenderNode ** senders;
  ReceiverNode ** receivers;
  Node *** field;

 public:
  Field( int senders, int mules, int receivers,
	 int dim, EventList * elist );
  Node * getPos(int x, int y);
  Node * getInd( int index );
  void moveMules();
  void draw();
  void prnTable();

};
