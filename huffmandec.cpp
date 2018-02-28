//Jiahong Chen, jc4tf, Apr18, huffmandec.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "hmtree.h"
#include "hmnode.h"

using namespace std;

int main (int argc, char **argv) {
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }
  ifstream file(argv[1], ifstream::binary);
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
   
    hmtree t;
    
  // read in the first section of the file: the prefix codes
  while ( true ) {
    string character, prefix;
    file >> character;
    if ( (character[0] == '-') && (character.length() > 1) )
      break;
    if ( character == "space" )
      character = " ";
    file >> prefix;
    //cout << "character '" << character << "' has prefix code '"<< prefix << "'" << endl;
      const char* temp = character.c_str();
      char ele = temp[0];
      t.makeTree(t.root,prefix,ele);
  }

  // read in the second section of the file: the encoded message
  stringstream sstm;
  while ( true ) {
    string bits;
    file >> bits;
    if ( bits[0] == '-' )
      break;
    sstm << bits;
  }

    string allbits = sstm.str();
        //cout << "All the bits: " << allbits << endl;
    t.printCode(t.root, allbits);
    cout<<endl;

    // close the file before exiting
  file.close();
}
