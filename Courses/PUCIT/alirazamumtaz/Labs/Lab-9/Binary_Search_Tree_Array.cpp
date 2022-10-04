#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define NONODE -1

class BSTreeArray{
	int *x, size;
public:
	BSTreeArray(const int SIZE){
		size = SIZE;
		this->x = new int[size];
		for (int i=0;i<size;i++)
			x[i] = NONODE;
	}
	//Worker Function
	void insert(int index, int data){
		if (index>=size)	return;
		if (x[index] == NONODE)	{
			x[index] = data;
			return;
		}
		if (x[index]>data)	
			insert(index*2, data);
		else
			insert(index*2+1, data);
	}
	//Wrapper Function
	void insert(int data){
		insert(1, data);
	}
	int findHighest(int index){
		while (index*2+1 < size && x[index*2+1]!=NONODE)
			index = index * 2 + 1;
		return index;
	}
	int findLowest(int index){
		while (index*2 < size && x[index*2]!=NONODE)
			index = index * 2 ;
		return index;
	}
	bool isNode(int index){
		if (index<size && x[index] != NONODE)	return true;
		return false;
	}
	void deleteNode(int index, int data){
		if (index>=size)		return;
		if (x[index]== NONODE)	return;
		if (x[index]>data)	
			deleteNode(index*2, data);
		else if (x[index]<data)
			deleteNode(index*2+1, data);
		else{//data found
			if (!isNode(index*2) && !isNode(index*2+1)){
				x[index] = NONODE;
				return;
			}
			else if (!isNode(index*2)){
				int lowestIndex = findLowest(index*2+1);
				x[index] = x[lowestIndex];
				deleteNode (lowestIndex, x[lowestIndex]);
			}
			else{
				int highestIndex = findHighest(index*2);
				x[index] = x[highestIndex];
				deleteNode (highestIndex, x[highestIndex]);
			}
		}	
	}	
	void deleteNode(int data){
		deleteNode(1, data);
	}
	int findNode(int index, int data){
		if (index>=size)		return -1;
		if (x[index]== NONODE)	return -1;
		if (x[index]>data)	
			return findNode(index*2, data);
		else if (x[index]<data)
			return findNode(index*2+1, data);
		else
			return index;
	}	
	int findNode(int data){
		return findNode(1, data);
	}
	void preOrder(int i){
		if (i >= size || x[i] == NONODE)
			return;
		cout << x[i] << ' ';
		preOrder(2*i);
		preOrder(2*i+1);
	}
	void preOrder(){
		preOrder(1);
		cout << '\n';
	}
	void inOrder(int i){
		if (i >= size || x[i] == NONODE)
			return;
		inOrder(2*i);
		cout << x[i] << ' ';
		inOrder(2*i+1);
	}
	void inOrder(){
		inOrder(1);
		cout << '\n';
	}
	int findHeight(int i){
		if (i>=size || x[i]==NONODE)	return -1;
		int h1 = findHeight(2*i);
		int h2 = findHeight(2*i+1);
		if (h1 > h2)	return h1+1;
		else 			return h2+1;
	}
	int findHeight(){
		return findHeight(1);
	}
	// A --------------------------------------------
	long long treeSum(int i){
		static long long sum = 0;
		if (i >= size || x[i] == NONODE)
			return 0;
		treeSum(2*i);
		sum +=  x[i];
		treeSum(2*i+1);
		return sum;
	}
	long long treeSum(){
		treeSum(1);
	}
	// B --------------------------------------------
	int countNodes(int head,int index){
		static int count = 1;
		if(index < head || x[index] == NONODE){
			count++;
		}
		else{
		countNodes(2*index);
		countNodes(2*index+1);
		count += 2;
		}
		return count;
	}
	int countNodes(int head){
		return countNodes(head,1);
	}
	// C ---------------------------------------------
	bool isEqual (BSTreeArray &t, int i, bool notSame){	
		if(x[i] == NONODE && t.x[i] != NONODE)
			notSame = false;
		if (i >= size || x[i] == NONODE)
			return notSame;
		notSame = isEqual(t, 2*i, notSame);
		if(x[i] != t.x[i])
			notSame = false;
		notSame = isEqual(t, 2*i+1, notSame);
		return notSame;
	}
	bool isEqual(BSTreeArray& t){
		return isEqual(t,1,true);
	}
	
	// D ---------------------------------------------
	static bool isBST(int* arr, int size){
		int left, right;
		for (int i = 1; i <= size/2 - 1; ++i){
			left = arr[i*2], right = arr[i*2+1];
			if(left < right && left < arr[i] && arr[i] <= right)
				return false;
		}
		return true;
	}	
// -----------------------------------------------------------------------
	~BSTreeArray(){	delete []x;	}
};



int main(){
	// int sum = 13+10+2+12+25+20+31+29+89;
	// BSTreeArray tree(20);
	// tree.insert(13);
	// tree.insert(10);
	// tree.insert(2);
	
	// tree.insert(25);
	// tree.insert(20);
	// tree.insert(31);
	// tree.insert(29);
	// tree.insert(89);
	// tree.printA	rr();
	// tree.preOrder();
	// tree.inOrder();
	// tree.postOrder();
	// tree.inOrder();
	// BSTreeArray t2(20);
	// t2.insert(13);
	// t2.insert(10);
	// t2.insert(2);
	// t2.insert(12);
	// t2.insert(25);
	// t2.insert(20);
	// t2.insert(31);
	// t2.insert(29);
	// t2.insert(89);
	// cout << "Height:" << tree.findHeight() << '\n';
	// cout << "Actual Sum: " << sum << '\n';
	// cout << "Sum of tree: " << tree.treeSum() << '\n';
	// cout << "count of nodes: " << tree.countNodes(3)<< '\n';
	// if(tree.isEqual(t2))
	// 	cout << "Equal\n";
	// else
	// 	cout << "Not Equal\n";
	int arr[16];
	srand(time(0));
	for (int i = 1;i<16;i++){
		arr[i] = rand()%100;
		cout << arr[i] << ' ';
	}
	cout << '\n';
	if(BSTreeArray::isBST(arr,8))
		cout << "Given array is a Binary Search Tree\n";
	else
		cout << "Given array is NOT a Binary Search Tree\n";
	return 0;
}
