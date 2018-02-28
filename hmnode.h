//Jiahong Chen, jc4tf, Apr16, hmnode.h
#include <iostream>
using namespace std;
#ifndef HMNODE_H
#define HMNODE_H

class hmnode {
public:
    hmnode();
    hmnode(int x, char y);
    ~hmnode();
    int freq;
    hmnode *left;
    hmnode *right;
    char ele;
    bool operator<(const hmnode &n) const;

};

#endif
