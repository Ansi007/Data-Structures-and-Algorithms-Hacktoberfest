#include<iostream>

#include "BST.h"
#include "BST.cpp"
using namespace std;



int main()
{
	BST<int> tree;
	int val;
	for (int i = 0; i < 7; i++)
	{
		cout << "=> Enter the value to be inserted: ";	cin >> val;
		tree.insert(val);
	}

	cout << endl;
	cout << "=>  Displaying Nodes (inOrder): ";
	tree.printNodes(tree.getRoot()); cout << endl << endl;

	BST<int> tree1 = tree;
	cout << "=>  Displaying Nodes of copy constructed tree: ";
	tree1.printNodes(tree1.getRoot()); cout << endl << endl;

	cout << "=> Max value in tree is: ";
	cout << tree.findMax() << endl << endl;

	cout << "=> Min value in tree is: ";
	cout << tree.findMin() << endl << endl;

	cout << "=> Give node, which descedents you wants to display: ";  cin >> val;
	cout << "=> Displaying Descedents(inOrder Traversal) after \"" << val << "\" ";
	tree.displayDescedents(val); cout << endl;

	cout << "=> Give node, which Ancestors you wants to display: ";  cin >> val;
	cout << "=> Displaying Ancestors before \"" << val << "\" ";
	tree.displayAncestors(val);	cout << endl;


	if (tree.isEqual(tree.getRoot(), tree1.getRoot())) {
		cout << "=> Trees are equal. " << endl;
	}

	else cout << "=> Trees are not equal. " << endl;


	if (tree.isBST(tree.getRoot())) {
		cout << "=> Tree is BST. " << endl;
	}

	else cout << "=> Tree is not BST. " << endl;

	cout << "=> Number of nodes in tree are: ";
	cout << tree.getNodeCount(&tree); cout << endl;

	cout << "=> Height of tree is: ";
	cout << tree.getHeight(); cout << endl;

	cout << "Deleting Root of tree: " << endl;
	BSTNode<int>* root = tree.getRoot();
	tree.deleteNode(root->data);
	tree1.printNodes(tree.getRoot()); cout << endl << endl;

	cout << "=> Tree1 (LevelOrder): " << endl;
	tree1.printTree();

	tree1.getMirrorImage();
	cout << "=> Tree1 Mirrored: ";
	cout << endl;
	tree1.printNodes(tree1.getRoot()); cout << endl << endl;
	

	return 0;
}
