#pragma once

template<class T>
class BinaryTree
{
private:
	int height; // represent the maximum possible height of the tree.
	T* data; // stores the tree nodes.
	bool* status; // this array is used to find that whether there is a
	// node on a particular index or not. If there is a valid
	// node exitsts on a particular index the status array holds
	// 'true' on corresponding index.
	int Size;
	int getIndex(T val);		//get Index from value
	void removeLeft(int i);	//remove left node
	void removeRight(int i);	//remove right node
	void printPreLeft(int i);		//print preLeft node
	void printPreRight(int i);	//printPre right node
	void printPostLeft(int i);	//print Post left
	void printPostRight(int i);	//print post right
	void printInLeft(int i);	//print Inorder left
	void printInRight(int i);	//print inorder right

public:
	BinaryTree(int h); //initializes all the data members
	~BinaryTree();	//destructor
	void setRoot(T val); // set val at data[0] as a root of tree and set status[0] = true;
	T getRoot(); // returns the root of tree if exists.
	void setLeftChild(T parent, T val); // sets the left child of given Parent.
	void setRightChild(T parent, T val);
	int getParent(int node); // returns the index of parent node.
	int getLeftChild(int par);
	int getRightChild(int par);
	void remove(T node); // remove the given node and all its descendants.
	void preOrder(); // display tree nodes using preOrder Traversal.
	void postOrder(); // display tree nodes using postOrder Traversal.
	void inOrder(); // display tree nodes using inOrder Traversal.
	void levelOrder(); // display tree nodes using levelOrder Traversal.
	void displayAncestors(T node);
	void displayDescendents(T node);
	bool isPerfectTree(); // returns true if the tree is perfect, otherwise false.
	bool isCompleteTree(); // returns true if the tree is perfect, otherwise false.
};

