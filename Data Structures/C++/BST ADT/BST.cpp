#include <iostream>
#include "node.cpp"
#include "circularqueue.cpp"

class BST {
public:
    Node *root ;
    Queue <Node*> q ;


    BST() {root = NULL ;}

    void insert (int key) {
        Node *temp = root;
        Node *prev , *next;

        if (root == NULL) 
            root = new Node(key) ;
        else {
            while (temp!= NULL) {
                prev = temp ;
                if (key < temp->data)
                    temp = temp->lchild ;
                else if (key > temp->data)
                    temp = temp->rchild ;
                else return ;
            
            }
        next = new Node(key) ;
        if (key < prev->data) prev->lchild = next;
        else prev->rchild = next;
        }
    }

    bool check_BST(Node *root) {
        Node *temp = root ;
        bool flag = false ;
        if (temp!=NULL) {
            if (temp->data > temp->lchild->data or temp->data < temp->rchild->data) 
                flag = true;
            else {
                check_BST(temp->lchild) ;
                check_BST(temp->rchild) ;
            }
        }
        return flag;
    }

    void inorder(Node *temp) {
        if (temp) {
            inorder(temp->lchild) ;
            cout << temp->data << ' ' ;
            inorder(temp->rchild) ;
        }
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

    void levelorder() {
        q.enqueue(root) ;
        while (!q.isempty()) {
            Node *temp ;
            temp = q.dequeue();
            if (temp!= NULL) {
                cout << temp->data << ' ' ;
                if (temp->lchild!= NULL) 
                    q.enqueue(temp->lchild);
                if (temp->rchild!= NULL) 
                    q.enqueue(temp->rchild);
            }
            
        }
    }

    bool search(int element) {
        Node *temp = root ;
        while (temp != NULL) {
            if (temp->data == element) return true;
            else if (temp->data < element) temp = temp ->rchild;
            else temp = temp ->lchild;
        }
        return false ;
    }

    	Node* findsuc(Node* n) {
			Node* temp = n;
			while(temp!= NULL)
			    temp = temp->lchild;
			return temp;
		}

		Node* deletion(Node *node, int val)
		{
			if(node == NULL)    return node;
			else if(val < node->data)     node->lchild = deletion(node->lchild,val);
			else if(val>node->data)       node->rchild = deletion(node->rchild,val);
			else
			{
				if(node->lchild==NULL && node->rchild == NULL)
				{
					delete node;
					node = NULL;
				}
				else if(node->lchild == NULL)
				{
					Node *temp = node;
					node = node->rchild;
					delete temp;
				}
				else if(node->rchild == NULL)
				{
					Node *temp = node;
					node = node->lchild;
					delete temp;	
				}
				else
				{
					Node *temp = findsuc(node->rchild);
					node->data = temp->data;
					node->rchild = deletion(node->rchild , node->data);
				}
				return node;
			}
        }
};


int main() {
	BST tree ;
    tree.insert(30) ;
    tree.insert(25) ;
    tree.insert(35) ;
    tree.insert(5) ;
    tree.insert(10) ;
    tree.insert(0) ;
    

   // cout << "Inorder expression is: " ;
   // tree.inorder(tree.root) ;
   // cout << endl ;
   // cout << "Preorder expression is: " ;
     //tree.preorder(tree.root) ;
     //cout << endl ;
     //cout << "Postorder expression is: " ;
     //tree.postorder(tree.root) ;
    //cout << endl ;
     if (tree.search(30)) cout << "Search successful\n" ;
     else cout << "Search unsuccessful\n" ;
     Node *res;
     if (tree.check_BST(tree.root)) cout << "It is BST\n" ;
    else cout << "It is not BST\n" ;
     res = tree.deletion(tree.root , 15) ;
     cout << "Inorder expression is: " ;
     tree.inorder(res) ;
    // cout << "Level order expression is: " ;
   //  tree.levelorder() ;
     cout << endl ;
    
}