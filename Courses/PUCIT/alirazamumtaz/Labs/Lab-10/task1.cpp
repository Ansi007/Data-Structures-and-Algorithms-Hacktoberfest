#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BST {
	struct BTNode {
		int data;
		BTNode *left, *right;
		BTNode(int data, BTNode *left = NULL, BTNode *right = NULL) {
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BST() {	root = NULL;	}
	BTNode* add(int d, BTNode *t) {
		if (t == NULL)	return new BTNode(d);
		if (t->data > d) 		t->left = add(d, t->left);
		else if (t->data < d) t->right = add(d, t->right);
		return t;
	}
	void add(int d) {
		root = add(d, root);
	}
	void inorder(BTNode* t) {
		if (t != NULL) {
			inorder(t->left);
			cout << t->data << ' ';
			inorder(t->right);
		}
	}
	void inorder() {
		inorder(root);
		cout << '\n';
	}
	void preorder(BTNode* t) {
		if (t != NULL) {
			cout << t->data << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder() {
		preorder(root);
		cout << '\n';
	}
	int countNodes(BTNode *t) {
		//Count nodes as we calculate height, instead of finding max, add left and right
		if (t == NULL)	return -1;
		int lC = countNodes(t->left) + 1;
		int rC = countNodes(t->right) + 1;
		return lC + rC;
	}
	int countNodes() {
		return countNodes(root);
	}
	int inOrderArray(BTNode *t, int *array, int index) {
		if (t != NULL) {
			//call function for left of tree and get index
			index = inOrderArray(t->left, array, index);
			//store value of current node in array according to index
			array[index] = t->data;
			//call function for right of tree with index+1 and get index
			index = inOrderArray(t->right, array, index + 1);
			return index;
		}
		return index;
	}
	void inOrderArray(int* arr, int i) {
		inOrderArray(root, arr, i);
	}
	void addBinarySearch(int *array, int start, int end) {
		int mid;
		if (start <= end) {
			//calculate middle index
			mid = (start + end) / 2;
			//add element in BST from middle
			add(array[mid]);
			//call same function for left sub-array
			addBinarySearch(array, start, mid - 1);
			//call same function for right sub-array
			addBinarySearch(array, mid + 1, end);
		}
	}
	void checkAndBalanceTree(int countNodes) {
		//declare arrya of approriate size
		int* arr;
		arr = new int[countNodes + 1];
		//call inorderArray with appropriate arguments
		int index = inOrderArray(root, arr, 1);
		for (int i = 1; i < countNodes; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		//remove BST
		removeNodes(root);
		//call addBinarySearch with appropriate arguments
		addBinarySearch(arr, 1, countNodes);
	}
	void checkAndBalance() {
		//get left count at root
		int lC = countNodes(root -> left);
		//get right count at root
		int rC = countNodes(root -> right);
		//get difference
		int diff = lC - rC;
		//if difference is inappropriate
		if (diff > 1 or diff < -1)
			checkAndBalanceTree(lC + rC + 1);
		//call checkAndBalanceTree with appropriate arguments;
	}
	void postOrder(BTNode* curr) {
		if (curr == NULL) return;
		postOrder(curr->left);
		postOrder(curr->right);
		cout << curr->data << ' ';
	}
	void postOrder() {
		postOrder(root);
		cout << "\n";
	}
	void removeNodes(BTNode* t) {
		if (t == NULL)	return;
		//call this function for left
		removeNodes(t->left);
		//call this function for right
		removeNodes(t->right);
		//delete t
		delete t;
		t = NULL;
	}
	~BST() {
		removeNodes(root);
	}
};

int main() {
	srand(time(0));
	BST tree;
	for (int i = 0; i < 10; i++)
		tree.add(rand() % 900 + 100);
	// tree.add(5);
	// tree.add(4);
	// tree.add(6);
	cout << "Nodes are: " << tree.countNodes() << '\n';
	// cout << "Preorder : "; tree.preorder();	cout << '\n';
	cout << "Inorder  : "; tree.inorder();	cout << '\n';
	// cout << "PosstOrder: "; tree.postOrder();	cout << '\n';
	// cout << "Inorder  : "; tree.inorder();	cout << '\n';
	tree.checkAndBalance();
	// tree.preorder();
	// tree.inorder();
	return 0;
}