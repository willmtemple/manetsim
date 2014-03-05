# MANETSIM

#### Authors: William M. Temple & Sonam T. Sherpa
#### Group: 3D

The program is a simulator for mobile ad-hoc networks, or MANETS that operate on a mesh/grid system. The program arrays three different types of nodes ( SENDER, RECEIVER, and MULE ) on a "playfield." The senders then communicate packets to the receivers by routing them through known routes along the mule nodes.

To compile the program, run

> make

To automatically test the program using the supplied prog5.txt, run

> make test

which will dump the output (including stderr) into a file called "prog5.out."

##How it works:

The program accepts command-line arguments of the following form:

>manetsim [SOURCES] [RECEIVERS] [MULES] [DIMENSION]

where SOURCES indicates the number of sender nodes, RECEIVERS indicates the number of receiver/endpoint nodes, MULES indicates the number of mules to array across the field, and DIMENSION indicates the width of the square "playfield."

The program is designed such that the sources are always randomly assigned to rows on the west side of the field, and the receivers are always arrayed to the east of the field. The mules are randomly placed into coordinates on the field. Additionally, once per 10 simulation time units, the mules each move in a random (determined randomly at runtime) direction. Should they run into a wall, they will bounce in the opposite direction immediately.

The simulation is event driven, with each packet's event times determined by the propagation and transmission times of each node and packet. A node's propagation time to another node is determined by the smallest integer not less than the binary logarithm of the euclidean distance between the two nodes' coordinates. The transmission time is determined by the packet's size (determined at runtime).

The program gathers information for creating source nodes from a script file (via stdin) formatted as follows:

> [ID] [ARRIVAL_TIME] [PACKETS] [PKT_SIZE] [SR_SIZE] [SR ...]

where ID is the numerical unique identifier for the node, ARRIVAL_TIME is the time at which the source node begins sending packets, PACKETS is the integer number of packets to be sent by this node, PKT_SIZE is the integer size of the packets that this node sends, SR_SIZE is the length of SR (in distinguishable integers), and SR is a space-delimited list of integers which determine the route that packets created by this node will follow..

