//Jiahong Chen, jc4tf, Apr16, hmtree.h
#include <iostream>
#include "hmnode.h"
#include "heap.h"
using namespace std;

#ifndef HMTREE_H
#define HMTREE_H

class hmtree {
public:
    hmtree();
    ~hmtree();
    void buildTree(heap h);
    void opcode(hmnode* ptr, string prefix);
    int getCode (hmnode* ptr, string prefix, char c);
    void makeTree(hmnode* curr, string prefix, char e);
    void printCode (hmnode *curr, string allBits);
    hmnode* root;
    int comp_bits;
};

#endif
