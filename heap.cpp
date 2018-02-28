//Jiahong Chen, Apr16, jc4tf, heap.cpp
#include <iostream>
using namespace std;
#include "heap.h"
#include <iostream>
using namespace std;

// default constructor
heap::heap(){
    heap_size = 0;
    minheap.push_back(0);
}

//destructor
heap::~heap() {
}


void heap::insert(hmnode* x){
    if(heap_size==minheap.size()-1)
        minheap.resize(minheap.size()*2);
    heap_size++;
    int hole=heap_size;
    for(; hole>1 && *x<*minheap[hole/2];hole/=2)
        minheap[hole]=minheap[hole/2];
    minheap[hole]=x;
}


hmnode* heap::deleteMin(){
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    hmnode* ret = minheap[1];
    minheap[1] = minheap[heap_size--];
    minheap.pop_back();
    percolateDown(1);
    return ret;
}

void heap::percolateDown(int hole) {
    hmnode *x = minheap[hole];
    while ( hole*2 <= heap_size ) {
        int child = hole*2;
        if ( (child+1 <= heap_size) && (minheap[child+1]->freq < minheap[child]->freq) )
            child++;
        if ( x->freq > minheap[child]->freq ) {
            minheap[hole] = minheap[child];
            hole = child;
        } else
            break;
    }
    minheap[hole] = x;
}

//void heap::print() {
//    for ( int i = 1; i <= heap_size; i++ ) {
//        cout<<minheap[i]->freq<<" ";}
//    cout<<endl;
//}

