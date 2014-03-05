all: manetsim

manetsim: main.o PacketQueue.o PacketEvent.o EventList.o Route.o SenderNode.o ReceiverNode.o Field.o MuleNode.o Node.o
	g++ -o manetsim *.o

main.o: main.cpp global.h
	g++ -c -g -Wall main.cpp

PacketQueue.o: PacketQueue.cpp PacketQueue.h PacketEvent.h Event.h
	g++ -c -g -Wall PacketQueue.cpp

PacketEvent.o: PacketEvent.cpp PacketEvent.h Event.h
	g++ -c -g -Wall PacketEvent.cpp

EventList.o: EventList.cpp EventList.h Event.h
	g++ -c -g -Wall EventList.cpp

Route.o: Route.cpp Route.h
	g++ -c -g -Wall Route.cpp

Node.o: Node.cpp Node.h
	g++ -c -g -Wall Node.cpp

SenderNode.o: SenderNode.cpp SenderNode.h
	g++ -c -g -Wall SenderNode.cpp

ReceiverNode.o: ReceiverNode.cpp ReceiverNode.h
	g++ -c -g -Wall ReceiverNode.cpp

MuleNode.o: MuleNode.cpp ReceiverNode.h
	g++ -c -g -Wall MuleNode.cpp

Field.o: Field.cpp Field.h
	g++ -c -g -Wall Field.cpp

clean:
	rm -f *.tar *.o *.out manetsim

test: manetsim Makefile prog5.txt
	./manetsim 20 10 24 30 < prog5.txt &> test.out

tar: test README.md
	tar -cvf manet.tar *.cpp *.h *.out *.txt Makefile README.md
