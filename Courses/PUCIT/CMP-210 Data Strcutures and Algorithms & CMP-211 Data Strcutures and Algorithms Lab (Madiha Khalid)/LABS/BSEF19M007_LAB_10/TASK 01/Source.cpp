#include<iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;


int main() {

	int h, val, par,size;
	cout << "=> Give Height of the tree: "; cin >> h;
	BinaryTree<int> tree(h);
	cout << "=> Give root: "; cin >> val;
	tree.setRoot(val);
	size = (pow(2, h) - 1)/2;
	for (int i = 0; i < size; i++) {
		cout << "=> Give parent's value whose child you want to set: "; cin >> par;
		cout << "=> Give left child: "; cin >> val;
		tree.setLeftChild(par, val);

		cout << "=> Give right child: "; cin >> val;
		tree.setRightChild(par, val);
		cout << endl;
	}

	cout << "=> Pre Order tree: "; tree.preOrder();
	cout << "=> Post Order tree: "; tree.postOrder();
	cout << "=> In Order tree: "; tree.inOrder();
	cout << "=> Level Order tree: "; tree.levelOrder();
	cout << endl;
	cout << "=> Give child whose parent's you want to see: "; cin >> val;
	tree.displayAncestors(val);

	cout << "=> Give parnet whose child you want to see: "; cin >> val;
	tree.displayDescendents(val);

	if (tree.isPerfectTree())
		cout << "=> It is a perfect tree. " << endl;
	else 		
		cout << "=> It is not a perfect tree. " << endl;

	if (tree.isCompleteTree())
		cout << "=> It is complete tree." << endl;
	else 
		cout << "=> It is complete tree." << endl;

	cout << "=> Give a node you want to remove: "; cin >> val;
	tree.remove(val);
	cout << "=> Level Order tree: "; tree.levelOrder();

	cout << "=> Give parent index and get its left child index: "; cin >> par;
	cout << tree.getLeftChild(par) << endl;

	cout << "=> Give parent index and get its right child index: "; cin >> par;
	cout << tree.getRightChild(par) << endl;

	cout << "=> Give child's index and get its parent index: "; cin >> val;
	cout << tree.getParent(val) << endl;

	return 0;
}