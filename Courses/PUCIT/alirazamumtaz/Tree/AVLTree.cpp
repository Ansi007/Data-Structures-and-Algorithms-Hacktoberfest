#include <iostream>

using namespace std;

template<class T>
class AVL {
private:
	class TreeNode {
	public:
		T data;
		TreeNode *left, *right;

		TreeNode(const T data)
			: data(data), left(NULL), right(NULL)
		{}
	};
public:
	TreeNode *root;
	AVL():
		root(NULL) {}

	void insert(T data) {
		root = _ensureBalance(insert(data, root));
	}

	TreeNode* insert(T data, TreeNode* curr) {
		if (curr == NULL) return new TreeNode(data);

		if (curr->data > data)
			curr->left = insert(data, curr->left);
		else
			curr->right = insert(data, curr->right);

		return _ensureBalance(curr);
	}

	bool search(T data) const {
		return search(data, root);
	}

	bool search(T data, TreeNode* curr) const {
		// Base Cases
		if (curr == NULL) return false;

		if (curr->data == data) return true;

		// Recursive Case
		if (curr->data > data)
			return search(data, curr->left);
		else
			return search(data, curr->right);
	}

	int height() const {
		return height(root);
	}

	int height(TreeNode* curr) const {
		// Base Case
		if (curr == NULL) return -1;
		// Recursive
		return max(height(curr->left), height(curr->right)) + 1;
	}

	void remove(T data) {
		root = _ensureBalance(remove(data, root));
	}

	TreeNode* remove(T data, TreeNode* curr) {
		// Base Case
		if (curr == NULL) return NULL;

		if (curr->data == data) {
			// no child case
			if (curr->left == NULL and curr->right == NULL) {
				delete(curr);
				return NULL;
			}
			// two child case
			if (curr->left != NULL and curr->right != NULL) {
				TreeNode* iop = findRightMost(curr->left);
				curr->data = iop->data;
				curr->left = remove(iop->data, curr->left);
				return _ensureBalance(curr);
			}
			// one child
			TreeNode* temp = curr->left ? curr->left : curr->right;
			delete(curr);
			return temp;
		}

		// Recursive Case
		if (curr->data > data)
			curr->left = remove(data, curr->left);
		else
			curr->right = remove(data, curr->right);

		return _ensureBalance(curr);
	}

	TreeNode* findRightMost(TreeNode* curr) {
		// Base Case
		if (curr->right == NULL) return curr;
		return findRightMost(curr->right);
	}
private:
	int _getBalanceFactor(TreeNode* curr) {
		if (curr == NULL) return 0;
		return height(curr->left) - height(curr->right);
	}

	TreeNode* _ensureBalance(TreeNode* curr) {
		int initial_balance = _getBalanceFactor(curr);
		// Left heavy
		if (initial_balance >= 2) {
			int l_balance = _getBalanceFactor(curr->left);
			if (l_balance >= 0) //stick structure
				return _rightRotation(curr);
			else {// elbow structure
				curr->left = _leftRotation(curr->left);
				return _rightRotation(curr);
			}
		}
		// Right heavy
		if (initial_balance <= -2) {
			int r_balance = _getBalanceFactor(curr->right);
			if (r_balance <= 0) //stick structure
				return _leftRotation(curr);
			else {// elbow structure
				curr->right = _rightRotation(curr->right);
				return _leftRotation(curr);
			}
		}

		// Tree is in balance
		return curr;
	}

	TreeNode* _rightRotation(TreeNode* curr) {
		if (curr == NULL or curr->left == NULL)
			throw runtime_error("Invalid Right Rotation Called");

		TreeNode* next = curr->left;
		// Moving Substructure
		curr->left = next->right;
		// Move Current Down
		next->right = curr;
		// Throw the Node up
		return next;
	}

	TreeNode* _leftRotation(TreeNode* curr) {
		if (curr == NULL or curr->right == NULL)
			throw runtime_error("Invalid Left Rotation Called");

		TreeNode* next = curr->right;
		// Moving Substructure
		curr->right = next->left;
		// Move Current Down
		next->left = curr;
		// Throw the Node up
		return next;
	}
public:
	void inOrder() const {
		inOrder(root);
		cout << '\n';
	}

	void inOrder(TreeNode* curr) const {
		if (curr == NULL) return;
		inOrder(curr->left);
		cout << curr->data << ' ';
		inOrder(curr->right);
	}

	void preOrder() const {
		preOrder(root);
		cout << '\n';
	}

	void preOrder(TreeNode* curr) const {
		if (curr == NULL) return;
		cout << curr->data << ' ';
		preOrder(curr->left);
		preOrder(curr->right);
	}
};

int main() {
	AVL<int> balanced_tree;
	balanced_tree.insert(50);
	balanced_tree.insert(35);
	balanced_tree.insert(93);
	balanced_tree.insert(80);
	balanced_tree.insert(100);
	balanced_tree.preOrder();
	balanced_tree.remove(35);
	balanced_tree.preOrder();
	return 0;
}