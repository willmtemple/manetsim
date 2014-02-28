all: manetsim

manetsim: main.o eventDispatch.o PacketQueue.o PacketEvent.o EventList.o Route.o
	g++ -o manetsim *.o

main.o: main.cpp global.h
	g++ -c -g -Wall main.cpp

eventDispatch.o: eventDispatch.cpp global.h
	g++ -c -g -Wall eventDispatch.cpp

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

clean:
	rm -f *.tar *.o *.out manetsim

test: manetsim Makefile
	./manetsim > test.out

tar: test README.md
	tar -cvf lab5.tar *.cpp *.h *.out Makefile README.md
