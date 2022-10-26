#ifndef NODE
#define NODE
#include <iostream>

using namespace std;

class Node{
public:
    Node *lchild;
    Node *rchild;
    int data ;
    Node (int data , Node *l=NULL, Node *r= NULL) {
        rchild = r;
        lchild = l;
        this->data = data ;
    }
};

#endif