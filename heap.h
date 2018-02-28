//Jiaong Chen, jc4tf, Apr 16, heap.h
#include <iostream>

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <vector>
#include "hmnode.h"
using namespace std;

class heap {
public:
    heap();
    ~heap();
    void insert(hmnode *hmn);
    hmnode* deleteMin();
    void percolateDown(int hole);
    //void print();
    vector<hmnode*> minheap;
    unsigned int heap_size;


};

#endif
