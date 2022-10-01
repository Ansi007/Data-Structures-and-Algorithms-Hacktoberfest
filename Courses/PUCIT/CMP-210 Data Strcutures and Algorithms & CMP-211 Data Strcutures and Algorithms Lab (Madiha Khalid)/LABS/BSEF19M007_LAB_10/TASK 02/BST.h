#pragma once
#include<iostream>
#include<stack>
#include <queue>

using namespace std;


template<class T>
class BST;

template<class T>
class BSTNode
{
public:
	friend BST<T>;
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode(T val)
	{
		data = val;
		left = right = NULL;
	}
};

template<class T>
class BST
{
private:
	BSTNode<T>* root;
	void helpDestruct(BSTNode<T>* node);	// Called by Wrapper function "~BST()"
	void helpConstruct(BSTNode<T>* node, BSTNode<T>* Tnode);	// Called by Wrapper function "BST(const BST& Tree)"
	bool helpAncest(BSTNode<T>* node, T val);	// Called by Wrapper function displayAncestors(T val);
	bool helpBST(BSTNode<T>* node, BSTNode<T>* left, BSTNode<T>* right); // Called by Wrapper function isBST();
	int helpHeight(BSTNode<T>* node);	// Called by Wrapper function int getHeight();	
	void helpMirrior(BSTNode<T>* node, BSTNode<T>* left, BSTNode<T>* right);
public:
	BST();	//Default constructor
	BST(const BST& Tree);	//copy constructor
	~BST();	//destructor
	void setRoot(T value);	//Set root of the tree
	BSTNode<T>* getRoot();	//Give root of the tree
	void insert(T val);	//Insert childs in tree. Auto adjusted per rules.
	BSTNode<T>* getLeftChild(BSTNode<T>* node);		//get left child of the node
	BSTNode<T>* getRightChild(BSTNode<T>* node);	//get right child of the node.
	BSTNode<T>* Search(T val);	//Search node in tree.
	void deleteNode(T val);	//delete any node
	void printNodes(BSTNode<T>* root);	//Print tree
	bool isBST(BSTNode<T>* root);	//Check if tree is a BST
	void printTree(); //print tree level order
	bool isEqual(BSTNode<T>* r1, BSTNode<T>* r2);	//Check if two trees are exactly the same
	bool isInternalNode(BSTNode<T>* node);	//Check if node is internal
	bool isExternalNode(BSTNode<T>* node);	//Check if node is external
	int getHeight();	//Get height of the tree i.e the longest path
	void displayAncestors(T val);	//Display forefathers of a node
	void displayDescedents(T val);	//Display all child of a node
	BST<T> getMirrorImage();	//make left child its right and vice versa
	int getNodeCount(BST<T>* tree);	//Get total count of nodes in tree.
	T findMin();	//Display minimum value from the tree.
	T findMax();	//Display maximum value from the tree.
};
