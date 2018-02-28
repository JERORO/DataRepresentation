//Jiahong Chen, jc4tf, Apr16, huffmanenc.cpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "heap.h"
#include "hmnode.h"
#include "hmtree.h"
using namespace std;

int main (int argc, char **argv) {
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    heap h1;
    
    vector<int> fre(128,0);
    int counts = 0;
    int diff_char = 0;
    
    char g;
    while ( (g = fgetc(fp)) != EOF ){
        int val = (int)g;
        if (val<128 && val>31){
            counts++;
            fre[val]++;}
        cout << g;
    }
    
    for (int i = 32; i<fre.size(); i++){
        if(fre[i]!=0){
            hmnode *pt = new hmnode(fre[i],(char)i);
            h1.insert(pt);
            diff_char ++;
        }
    }
    
    hmtree t;
    t.buildTree(h1);
    t.opcode(t.root, "");
    
    cout << "----------------------------------------" << endl;
    rewind(fp);
    
    int comp_bits;
    
    while ( (g = fgetc(fp)) != EOF )
         comp_bits = t.getCode(t.root, "", g);
    cout<<endl;

    cout << "----------------------------------------" << endl;
    cout<<"There are a total of "<<counts<<" symbols that are encoded."<<endl;
    cout<<"There are "<<diff_char<<" distinct symbols used."<<endl;
    cout<<"There were "<<counts*8<<" bits in the original file."<<endl;
    cout<<"There were "<<comp_bits<<" bits in the compressed file."<<endl;
    cout<<"This gives a compression ratio of "<<(double)counts*8/comp_bits<<" ."<<endl;
    cout<<"The cost of the Huffman tree is "<<(double)comp_bits/counts<<" bits per character."<<endl;
    
    fclose(fp);
}
