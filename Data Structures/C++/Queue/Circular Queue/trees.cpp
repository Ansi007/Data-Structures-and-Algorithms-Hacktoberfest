#include "circular_queue.cpp"
#include "node.cpp"
#include <iostream>

using namespace std;

class Tree {

public:
    Node *root ;

    Tree() {root = NULL ;}

    void createTree() {
        Node *p , *t ;
        Queue q(50);
        int temp_data ;
        root = new Node ; 
        cout << "Enter root data: " ;
        cin >> root->data ;     
        root ->lchild = NULL ;
        root ->rchild = NULL ;
        q.enqueue(root) ;

        while (!q.isempty()) {
            p = q.dequeue() ;
            cout << "Enter left child of " << p->data << " : " ;
            cin >> temp_data ;
            if (temp_data != -1) {
                t = new Node;
                t->data = temp_data ;
                t->lchild = t->rchild = NULL ;
                p->lchild = t;
                q.enqueue(t) ;
            }

            cout << "Enter right child : " << p->data << " : " ;
            cin >> temp_data ;
            if (temp_data != -1) {
                t = new Node;
                t->data = temp_data ;
                t->lchild = t->rchild = NULL ;
                p->rchild = t;
                q.enqueue(t) ;
            }
        }
        cout << "Tree created successfully\n" ;
    }

    void preorder(Node *p) {
        if (p!= NULL) {
            cout << p->data << ' ';
            preorder(p->lchild) ;
            preorder(p->rchild) ;
        }
    }

    void postorder(Node *p) {
        if (p!= NULL) {
            postorder(p->lchild) ;
            postorder(p->rchild) ;
            cout << p->data << ' ';
            
        }
    }

    void inorder(Node *p) {
        if (p!= NULL) {
            inorder(p->lchild) ;
            cout << p->data << ' ';
            inorder(p->rchild) ;          
        }
    }


};

int main() {
    Tree t;
    t.createTree();
    cout << "Preorder traversal is: " ;
    t.preorder(t.root) ;
    cout << endl ;
    cout << "Postorder traversal is: " ;
    t.postorder(t.root) ;
    cout << endl ;
    cout << "Inorder traversal is: " ;
    t.inorder(t.root) ;
    cout << endl ;


}