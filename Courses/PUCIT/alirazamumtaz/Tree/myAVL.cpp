#include <iostream>

using namespace std;

class myAVL {
public:
	//------------- Node Class -------------------------------
	class AVLNode {
	public:
		int data, height;
		AVLNode *left, *right;
		AVLNode(int d, AVLNode *l = NULL, AVLNode *r = NULL):
			data(d), height(0), left(l), right(r)
		{}
	};
	//--------------------------------------------------------
	AVLNode *root;
	myAVL():
		root(NULL)
	{}
	//--------------- Utilities ------------------------------
	int findHeight(AVLNode *node) {
		if (node == NULL) return -1;
		return node->height;
	}
	int findHeight() {
		if (root == NULL) return -1;
		int lH = findHeight(root->left);
		int rH = findHeight(root->right);
		if (lH > rH)
			return lH + 1;
		else
			return rH + 1;
	}
	void setHeight(AVLNode *node) {
		int lH = findHeight(node->left);
		int rH = findHeight(node->right);
		if (lH > rH)
			node->height = lH + 1;
		else
			node->height = rH + 1;
	}
	AVLNode* leftMost(AVLNode* curr) {
		if (curr->left == NULL) return curr;
		return leftMost(curr->left);
	}
	AVLNode* rightMost(AVLNode* curr) {
		if (curr->right == NULL) return curr;
		return rightMost(curr->right);
	}
	//----------------- Rotation Functions -------------------
	AVLNode* rotateLeft(AVLNode *node) {
		AVLNode* rightNode = node->right;
		node->right = rightNode->left;
		rightNode->left = node;
		setHeight(node);
		return rightNode;
	}
	AVLNode* rotateRight(AVLNode* node) {
		AVLNode* leftNode = node->left;
		node->left = leftNode->right;
		leftNode->right = node;
		setHeight(node);
		return leftNode;
	}
	//----------------- Check and Balance --------------------
	AVLNode* checkAndBalance(AVLNode *curr) {
		// Finding the balance factor
		int lH = findHeight(curr->left);
		int rH = findHeight(curr->right);
		int subLH, subRH;

		if (rH - lH >= 2) { // Left heavy tree

			subLH = findHeight(curr->left->left);
			subRH = findHeight(curr->left->right);
			if (subLH - subRH) //Single Right Rotation
				curr = rotateRight(curr);
			else { // Double Left Right Rotation
				curr = rotateLeft(curr->left);
				curr = rotateRight(curr);
			}
		}

		if (lH - rH >= 2) { // Right heavy tree

			subLH = findHeight(curr->right->left);
			subRH = findHeight(curr->right->right);
			if (subLH - subRH) //Single Left Rotation
				curr = rotateLeft(curr);
			else { // Double Right Left Rotation
				curr = rotateRight(curr->right);
				curr = rotateLeft(curr);
			}
		}
		setHeight(curr);
		return curr;
	}
	//---------------------- Insert --------------------------
	void insert(int d) {
		root = insert(d, root);
	}
	AVLNode* insert(int d, AVLNode* curr) {
		if (curr == NULL) {
			AVLNode* newNode = new AVLNode(d);
			return newNode;
		}
		if (curr->data > d)
			curr->left = insert(d, curr->left);
		else
			curr->right = insert(d, curr->right);
		return curr;
	}
	//------------------- Delete ------------------------------
	AVLNode* deleteNode(int d, AVLNode *temp) {
		AVLNode *next;
		if 		(temp == NULL)		return NULL;
		else if (temp->data > d)	temp->left = deleteNode(d, temp->left);
		else if (temp->data < d)	temp->right = deleteNode(d, temp->right);
		else { //Node found and to be deleted
			if (temp->left == NULL && temp->right == NULL) {
				delete temp;
				return NULL;
			}
			else if (temp->left == NULL) {
				next = temp->right;
				delete temp;
				temp = next;
			}
			else if (temp->right == NULL) {
				next = temp->left;
				delete temp;
				temp = next;
			}
			else {
				next = rightMost (temp->left);
				temp->data = next->data;
				temp->left = deleteNode(next->data, temp->left);
			}
		}
		return checkAndBalance(temp);
	}
	void deleteNode(int d) {
		root = checkAndBalance(deleteNode (d, root));
	}
	//---------------- Traversals -----------------------------
	void inOrder() {
		inOrder(root);
		cout << '\n';
	}
	void inOrder(AVLNode* curr) {
		if (curr == NULL) return;
		inOrder(curr->left);
		cout << curr->data << ' ';
		inOrder(curr->right);
	}
	void preOrder() {
		preOrder(root);
		cout << '\n';
	}
	void preOrder(AVLNode* curr) {
		if (curr == NULL) return;
		cout << curr->data << ' ';
		preOrder(curr->left);
		preOrder(curr->right);
	}
	//-------------------------------------------
};

int main(int argc, char const *argv[]) {
	myAVL balanced_tree;
	balanced_tree.insert(50);
	balanced_tree.insert(35);
	balanced_tree.insert(93);
	balanced_tree.insert(80);
	balanced_tree.insert(100);
	balanced_tree.preOrder();
	balanced_tree.deleteNode(35);
	balanced_tree.preOrder();
	/*myAVL tree;
	tree.insert(5);
	tree.insert(25);
	tree.insert(15);
	tree.insert(35);
	tree.insert(45);
	tree.insert(65);
	tree.inOrder(); tree.preOrder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.insert(85);
	tree.inOrder(); tree.preOrder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.insert(95);
	tree.inOrder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.insert(28);
	tree.insert(48);
	tree.insert(68);
	tree.insert(38);
	tree.insert(98);
	//tree.insert(18);
	tree.insert(78);
	tree.inOrder(); tree.preOrder();
	cout << "Height:"	<< tree.findHeight() << '\n';*/
	return 0;
}