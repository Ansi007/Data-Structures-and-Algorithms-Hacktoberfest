#include "BST.h"


template<class T>
BST<T>::BST()
{
	root = NULL;	//Default root is NULL
}

template<class T>
BST<T>::BST(const BST& Tree)
{
	if (Tree.root) {
		root = new BSTNode<T>(Tree.root->data);	//make root
		helpConstruct(root, Tree.root);	//recursively construct
	}
	else root = NULL;
}

template<class T>
BST<T>::~BST()
{
	helpDestruct(root);	//recursively destruct
}

template<class T>
void BST<T>::helpDestruct(BSTNode<T>* node)
{
	if (node) {
		helpDestruct(node->left);	//go to all nodes and delete them one by one
		helpDestruct(node->right);
		delete node;
	}
}

template<class T>
void BST<T>::helpConstruct(BSTNode<T>* node, BSTNode<T>* Tnode)
{
	if (Tnode) {	//go to all respective nodes and copy construct it.
		if (Tnode->left)
			node->left = new BSTNode<T>(Tnode->left->data);

		if (Tnode->right)
			node->right = new BSTNode<T>(Tnode->right->data);

		helpConstruct(node->left, Tnode->left);
		helpConstruct(node->right, Tnode->right);
	}
}

template<class T>
bool BST<T>::helpAncest(BSTNode<T>* node, T val)
{

	if (node) {	
		if (node->data == val)
			return true;
		else
		{
			if (node->data > val) {	//help print ancestors
				if (helpAncest(node->left, val)) {	//if left child
					cout << node->data << " ";
					return true;
				}
			}
			else {
				if (helpAncest(node->right, val)) {	//if right child
					cout << node->data << " ";
					return true;
				}
			}
		}
	}

	return false;
}

template<class T>
bool BST<T>::helpBST(BSTNode<T>* node, BSTNode<T>* left, BSTNode<T>* right)
{
	if (node) {

		if (left) {
			if (left->data > node->data)	//if left child rule is violated
				return false;
		}

		if (right) {
			if (right->data < node->data)	//if right child rule is violated
				return false;
		}

		return helpBST(node->left, left, node) && helpBST(node->right, node, right);

	}

	else return true;	//if all good
}

template<class T>
void BST<T>::setRoot(T value)
{
	root = new BSTNode<T>(value);	//SetRoot
}


template<class T>
BSTNode<T>* BST<T>::getRoot()
{
	return root;	//GetRoot
}

template<class T>
BSTNode<T>* BST<T>::getLeftChild(BSTNode<T>* node)
{
	if (node->left)
		return node->left;
	else return NULL;
}

template<class T>
BSTNode<T>* BST<T>::getRightChild(BSTNode<T>* node)
{
	if (node->right)
		return node->right;
	else return NULL;
}

template<class T>
void BST<T>::insert(T val)
{
	if (!root)	// when tree is empty
		root = new BSTNode<T>(val);
	else
	{
		//auto adjusting while inserting
		BSTNode<T>* temp = root;
		BSTNode<T>* prev = temp;
		while (temp)
		{
			if (temp->data > val)
			{
				prev = temp;
				temp = temp->left;
			}
			else
			{
				prev = temp;
				temp = temp->right;
			}
		}
		if (prev->data > val)
			prev->left = new BSTNode<T>(val);
		else
			prev->right = new BSTNode<T>(val);
	}
}

template<class T>
BSTNode<T>* BST<T>::Search(T val)
{
	BSTNode<T>* temp = root;
	while (temp)
	{
		if (temp->data == val)
			return temp;
		else
		{
			if (temp->data > val)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return NULL;
}
template<class T>
void BST<T>::printNodes(BSTNode<T>* root)
{
	//inOrder Traversal
	if (!root)
		return;
	printNodes(root->left);
	cout << root->data << " ";
	printNodes(root->right);
}

template<class T>
bool BST<T>::isBST(BSTNode<T>* root)
{
	//By wrapper function
	return (helpBST(root, NULL, NULL));	

}

template<class T>
int BST<T>::getHeight()
{
	//By wrapper function

	return(helpHeight(getRoot()));
}

template<class T>
BST<T> BST<T>::getMirrorImage()
{
	helpMirrior(root,root->left,root->right);
	return *this;
}

template<class T>
int BST<T>::getNodeCount(BST<T>* tree)
{
	//counting nodes using stack. 
	stack<BSTNode<T>*> S;
	BSTNode<T>* temp = tree->getRoot();
	int x = 0;

	if (!temp)
		return 0;
	// go to all nodes keep incrementing by 1
	while (temp != NULL || S.empty() == false) {

		while (temp != NULL) {
			S.push(temp);
			x++;
			temp = temp->left;
		}
		temp = S.top();	S.pop();
		temp = temp->right;
	}
	return x;
}


template<class T>
bool BST<T>::isEqual(BSTNode<T>* r1, BSTNode<T>* r2)
{
	if (r1 == NULL && r2 == NULL)	//if both dont exists
		return true;

	if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)	//if one node exists but other dont
		return false;


	if (r1->data != r2->data)	//if data not right
		return false;

	else {

		if (!(isEqual(r1->left, r2->left)))	//recursivly check each and every node
			return false;		

		if (!(isEqual(r1->right, r2->right)))
			return false;
		
	}
	return true;	//if all good return true.

}

template<class T>
bool BST<T>::isInternalNode(BSTNode<T>* node)
{
	return(node->left == true || node->right == true);	//if it has any child it is internal
}

template<class T>
bool BST<T>::isExternalNode(BSTNode<T>* node)
{
	return(node->left == false && node->right == false);	//if it do not have any child it is external
}

template<class T>
void BST<T>::displayAncestors(T val)
{
	//Wrapper function
	helpAncest(root, val);	
}

template<class T>
void BST<T>::displayDescedents(T val)
{
	BSTNode<T>* temp = Search(val);	//find the node, and display its descedents
	if (temp) {
		printNodes(temp->left);
		printNodes(temp->right);
	}
}

template<class T>
T BST<T>::findMin()
{
	//minimum is stored in extreme left
	BSTNode<T>* temp = root;
	while (temp->left)
	{
		temp = temp->left;
	}
	return temp->data;
}

template<class T>
T BST<T>::findMax()
{
	//maximum is stored in extreme right
	BSTNode<T>* temp = root;
	while (temp->right)
	{
		temp = temp->right;
	}
	return temp->data;
}


template<class T>
int BST<T>::helpHeight(BSTNode<T>* node)
{
	//help in counting height, by finding the longest path.
	if (!(node))
		return 0;
	else {
		int left = helpHeight(node->left);	//recursivley go to left
		int right = helpHeight(node->right);	//recursviel go to right

		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
	//PS: Idea is mine, only the counting is studied from net.
}

template<class T>
void BST<T>::helpMirrior(BSTNode<T>* node, BSTNode<T>* left, BSTNode<T>* right)
{
	
	if (node) {
		if(left)
			helpMirrior(left, left->left, left->right);

		if(right)
			helpMirrior(right, right->left, right->right);

		BSTNode<T>* temp;
		temp = left;
		node->left = node->right;
		node->right = temp;
	}
}



template<class T>
void BST<T>::deleteNode(T val)
{
	BSTNode<T>* toDelete = root;
	BSTNode<T>* prev = NULL;
	bool rightDel = false;

	while (toDelete)
	{
		if (toDelete->data == val) {
			break;
		}
		else
		{
			if (toDelete->data > val) {
				prev = toDelete;
				toDelete = toDelete->left;
				rightDel = false;
			}
			else {
				prev = toDelete;
				toDelete = toDelete->right;
				rightDel = true;
			}
		}
	}

	if (toDelete) {
		if (toDelete->left == NULL && toDelete->right == NULL)	// degree 0
		{
			delete toDelete;
			if (prev) {
				if (rightDel)
					prev->right = NULL;
				else
					prev->left = NULL;
			}
		}

		else if (toDelete->left != NULL && toDelete->right != NULL) // degree 2
		{
			BSTNode<T>* temp = toDelete->right;	
			while (temp->left)
			{
				temp = temp->left;
			}
			temp->data = toDelete->data;
			delete temp;
		}

		else // degree 1
		{
			if (prev) {
				if (rightDel) {
					if (toDelete->right)
						prev->right = toDelete->right;
				}
				else {
					if (toDelete->left) {
						prev->left = toDelete->left;
						delete toDelete;
					}
				}
			}
			else {
				if (root->right)
					root = root->right;
				else root = root->left;
				delete toDelete;
			}
		}
	}
}


template<class T>
void BST<T>::printTree()
{
	queue<BSTNode<T>*> Queue;
	BSTNode<T>* temp;

	Queue.push(getRoot());
	while (!(Queue.empty())) {
		temp = Queue.front();
		Queue.pop();
		cout << temp->data << " ";

		if (temp->left) {
			Queue.push(temp->left);
			cout << "/" << endl;
		}

		if (temp->right) {
			Queue.push(temp->right);
			cout << "\\" << endl;
		}
		cout << endl;
	}
}

