#Jiahong Chen, jc4tf, Apr 20, Makefile for postlab10
CXX	= clang++

CXXFLAGS	= -Wall -g

OFILES	= heap.o huffmanenc.o hmnode.o hmtree.o
OFILE	= huffmandec.o hmnode.o hmtree.o heap.o

.SUFFIXES: .o .cpp
all: encoder decoder
encoder:	$(OFILES)
	$(CXX) $(OFILES) -o encoder

decoder:	$(OFILE)
	$(CXX) $(OFILE) -o decoder

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out

hmtree.o: hmtree.cpp hmnode.h hmtree.h heap.h
hmnode.o: hmnode.cpp hmnode.h
heap.o: heap.cpp heap.h hmnode.h
huffmanenc.o: huffmanenc.cpp heap.h hmnode.h hmtree.h
huffmandec.o: huffmandec.cpp hmnode.h hmtree.h