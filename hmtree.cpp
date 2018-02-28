//Jiahong Chen, jc4tf, Apr 16, hmtree.cpp
#include <iostream>
using namespace std;
#include "hmtree.h"

hmtree::hmtree(){
    //root = NULL;
    root = new hmnode(2,'r');
    comp_bits = 0;
}

hmtree::~hmtree(){
    delete root;
}

void hmtree::buildTree(heap h){
    while (h.heap_size>1){
        hmnode* n1 = h.deleteMin();
        hmnode* n2 = h.deleteMin();
        int x = n1->freq;
        int y = n2->freq;
        hmnode *rt = new hmnode(x+y,'N');
        rt->left = n1;
        rt->right = n2;
        root = rt;
        h.insert(root);
    }
}

void hmtree::opcode(hmnode* ptr, string prefix){
    if (ptr->left==NULL && ptr->right == NULL){
        if (ptr->ele == ' '){
            cout<<"space "<<prefix<<endl;
        }else{
            cout<<ptr->ele<<" "<<prefix<<endl;
        }
    }if (ptr->left){
        opcode(ptr->left, prefix+"0");
    }if (ptr->right){
        opcode(ptr->right, prefix+"1");
    }
}

int hmtree::getCode(hmnode* ptr, string prefix, char c){
    if (ptr->ele == c && ptr->left==NULL && ptr->right == NULL){
        cout<<prefix<<" ";
        comp_bits += prefix.size();
    }if (ptr->left){
        getCode(ptr->left, prefix+"0", c);
    }if (ptr->right){
        getCode(ptr->right, prefix+"1", c);
    }
    return comp_bits;
}

void hmtree::makeTree(hmnode* curr, string prefix, char e){
    for (int i = 0; i < prefix.size();i++){
        if (prefix[i] == '0'){
            if(curr->left == NULL){
                curr->left = new hmnode(0, e);
                curr = curr->left;
            }else if (curr->left != NULL){
                curr = curr->left;
            }
        }else if (prefix[i] == '1'){
            if(curr->right == NULL){
                curr->right = new hmnode(1, e);
                curr = curr->right;
            }else if (curr->right != NULL){
                curr = curr->right;
            }
        }
    }
}

void hmtree::printCode(hmnode *curr, string allBits){
    hmnode *backup = new hmnode();
    backup = curr;
    for (int i = 0; i<allBits.size(); i++){
        if(allBits[i] == '0' && curr->left != NULL){
            curr = curr->left;
        }if(allBits[i] == '1' && curr->right !=NULL){
            curr = curr->right;
        }if(curr->left == NULL && curr->right==NULL){
            cout<<curr->ele;
            curr = backup;
        }
    }
}
