//Jiahong Chen, jc4tf, Apr16, hmnode.cpp
#include <iostream>
using namespace std;
#include "hmnode.h"

hmnode::hmnode(){
    left = NULL;
    right = NULL;
}

hmnode::hmnode(int x, char y){
    left = NULL;
    right = NULL;
    freq = x;
    ele = y;
}

hmnode::~hmnode(){
    delete left;
    delete right;
}

bool hmnode::operator<(const hmnode& n)const{
    return this->freq<n.freq;
}
