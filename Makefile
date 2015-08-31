CFLAGS = -c -g -Wall
CC = g++

all: clean bTree 

bTree: bTree.h node.h bTree.cpp node.cpp bTree_main.cpp
	$(CC) -o bTree bTree.h node.h bTree.cpp node.cpp bTree_main.cpp

clean:
	rm -rf *.o *.gch bTree