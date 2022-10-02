#include "BinaryTree.h"
#include<iostream>
using namespace std;

template<class T>
BinaryTree<T>::BinaryTree(int h)
{
	height = h;		
	Size = pow(2, h) - 1;		//calculating size of arrays
	data = new T[Size];
	status = new bool[Size];
	for (int i = 0; i < Size; i++) 
		status[i] = false;

}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	delete[] data;
	delete[] status;
}

template<class T>
void BinaryTree<T>::setRoot(T val)
{
	if (status[0] == false) {		
		data[0] = val;
		status[0] = true;
	}
}

template<class T>
T BinaryTree<T>::getRoot()
{
	if (status[0])
		return data[0];
	else return INT_MIN;
}

template<class T>
void BinaryTree<T>::setLeftChild(T parent, T val)
{
	int i = 0;	
	for (i; i < Size; i++) {		//Parent value is given, first we find the index of parent then we set its left child
		if (parent == data[i])
			break;

		if (i == Size - 1)
			return;
	}
	int leftIndex = 2 * i + 1;
	if (!(status[leftIndex])) {
		data[leftIndex] = val;
		status[leftIndex] = true;
	}
}

template<class T>
void BinaryTree<T>::setRightChild(T parent, T val)
{
	int i = 0;
	for (i; i < Size; i++) {	//find parent's index, then compute index, and set right child.
		if (parent == data[i])
			break;

		if (i == Size - 1)
			return;
	}
	int rightIndex = 2 * i + 2;
	if (!(status[rightIndex])) {
		data[rightIndex] = val;
		status[rightIndex] = true;
	}
}

template<class T>
int BinaryTree<T>::getParent(int node)
{
	int i = (node - 1)/2;	//Node's index is given, assumption: Because it is of "int" and not of "T". compute parent's index
	if (i >= 0 && i < Size && status[node] == true)
		return i;
	else return -1;	//if cant get
}

template<class T>
int BinaryTree<T>::getLeftChild(int par)
{
	int leftIndex = (2 * par) + 1;	//parent's index is given, return left index
	if (leftIndex > 0 && leftIndex < Size && status[leftIndex] == true)
		return leftIndex;
	else return -1;	//if cant get
}

template<class T>
int BinaryTree<T>::getRightChild(int par)
{
	int rightIndex = (2 * par) + 2;	//parent's index is given, return right child
	if (rightIndex > 0 && rightIndex < Size && status[rightIndex] == true)
		return rightIndex;
	else return -1;	//if cant get
}

template<class T>
int BinaryTree<T>::getIndex(T val)
{
	for (int i = 0; i < Size; i++) {	//find value's index
		if (val == data[i]) {
			return i;
		}
	}
	return -1;	//if not possible/exist
}

template<class T>
void BinaryTree<T>::remove(T node)
{
	int i = getIndex(node);	//find index
	if (i != -1) {
		status[i] = false;	//remove it,
		removeLeft(i);	//remove all Left of it
		removeRight(i);	//remove all right of it
	}
}

template<class T>
void BinaryTree<T>::removeLeft(int i)
{
	i = 2 * i + 1;	//helper function to removes left side
	if (i >= Size)
		return;
	status[i] = false;
	removeLeft(i);
	removeRight(i);

}

template<class T>
void BinaryTree<T>::removeRight(int i)
{
	i = 2 * i + 2;		//remove all right
	if (i >= Size)
		return;
	status[i] = false;
	removeLeft(i);
	removeRight(i);
}

template<class T>
void BinaryTree<T>::printPreLeft(int i)
{
	i = 2 * i + 1;	
	if (i >= Size || status[i] == false)
		return;
	cout << data[i] << " ";
	printPreLeft(i);
	printPreRight(i);
}

template<class T>
void BinaryTree<T>::printPreRight(int i)
{
	i = 2 * i + 2;
	if (i >= Size || status[i] == false)
		return;
	cout << data[i] << " ";
	printPreLeft(i);
	printPreRight(i);
}

template<class T>
void BinaryTree<T>::printPostLeft(int i)
{
	i = 2 * i + 1;
	if (i >= Size || status[i] == false)
		return;
	printPostLeft(i);
	printPostRight(i);
	cout << data[i] << " ";

}

template<class T>
void BinaryTree<T>::printPostRight(int i)
{
	i = 2 * i + 2;
	if (i >= Size || status[i] == false)
		return;
	printPostLeft(i);
	printPostRight(i);
	cout << data[i] << " ";
}

template<class T>
void BinaryTree<T>::printInLeft(int i)
{
	i = 2 * i + 1;
	if (i >= Size || status[i] == false)
		return;
	printInLeft(i);
	cout << data[i] << " ";
	printInRight(i);
}

template<class T>
void BinaryTree<T>::printInRight(int i)
{
	i = 2 * i + 2;
	if (i >= Size || status[i] == false)
		return;
	printInLeft(i);
	cout << data[i] << " ";
	printInRight(i);
}


template<class T>
void BinaryTree<T>::preOrder()
{
	if (status[0]) {
		cout << data[0] << " ";
		printPreLeft(0);
		printPreRight(0);
		cout << endl;
	}
}

template<class T>
void BinaryTree<T>::postOrder()
{
	if (status[0]) {
		printPostLeft(0);
		printPostRight(0);
		cout << data[0] << " ";
		cout << endl;
	}

}

template<class T>
void BinaryTree<T>::inOrder()
{
	if (status[0]) {
		printInLeft(0);
		cout << data[0] << " ";
		printInRight(0);
		cout << endl;
	}
}


template<class T>
void BinaryTree<T>::levelOrder()
{
	for (int i = 0; i < Size; i++) {

		if (status[i])
			cout << data[i] << " ";

	}
	cout << endl;
}

template<class T>
void BinaryTree<T>::displayAncestors(T node)
{
	int i = getIndex(node);
	if (i != -1) {
		while (i != 0) {
			i = (i - 1) / 2;
			cout << data[i] << " ";
		}
		cout << endl;
	}
}

template<class T>
void BinaryTree<T>::displayDescendents(T node)
{
	int i = getIndex(node);
	if (i != -1) {
			printPreLeft(i);
			printPreRight(i);
			cout << endl;
	}
}

template<class T>
bool BinaryTree<T>::isPerfectTree()
{
	for (int i = 0; i < Size; i++) {
		if (status[i]) {
			int LeftIndex = (2 * i) + 1;
			int RightIndex = LeftIndex + 1;
			if (status[LeftIndex] == true && status[RightIndex] == false || status[LeftIndex] == false && status[RightIndex] == true)	//all parent's have 2 or 0 child
				return false;
		}
	}
	return true;
}

template<class T>
bool BinaryTree<T>::isCompleteTree()
{
	// parents have 2 or 0 child, only second last child can have one. 
	for (int i = 0; i < Size; i++) {
		if (status[i]) {
			int LeftIndex = (2 * i) + 1;
			int RightIndex = LeftIndex + 1;

			if (status[LeftIndex] == true && status[RightIndex] == false) {

				int NLeftIndex = (2 * LeftIndex) + 1;
				int NRightIndex = LeftIndex + 1;

				if (status[NLeftIndex] == true || status[NRightIndex] == true)
					return false;

			}

			else if (status[LeftIndex] == false && status[RightIndex] == true) {
				return false;
			}			
		}
	}

	return true;
}


