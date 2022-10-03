#include <iostream>
#include <set>

template<class T>
class Linked_List {
private:
	// Internal Node Class
	class Node	{
	public:
		T data;
		Node* next;
		Node()
			: next(NULL)
		{}
		Node(T data)
			: data(data), next(NULL)
		{}
	};

	//
	Node *first, *last;
	size_t size;
public:
	bool isEmpty() const {return size == 0;}
	// Default Constructor
	Linked_List(): size(0) {}
	// add element at the bottom
	void push_back(const T data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			first = last = newNode;
		}	else {
			last->next = newNode;
			last = newNode;
		}
		size++;
		return;
	}
	// add element at the first
	void push_front(const T data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			first = last = newNode;
		}	else {
			newNode->next = first;
			first = newNode;
		}
		size++;
		return;
	}
	// insert at given index
	void insert_at(size_t index, const T data) {
		if (index > size) throw std::invalid_argument("Invalid Argument");
		if (index == 0) return push_front(data);
		if (index == size) return push_back(data);
		index--;
		Node * temp = first;
		while (index--) temp = temp->next;
		Node * newNode = new Node(data);
		newNode->next = temp->next;
		temp->next = newNode;
		size++;
		return ;
	}
	T pop_front() {
		if (isEmpty()) throw std::runtime_error("Empty List");
		size--;
		T temp_data = first->data;
		Node * temp = first;
		first = first->next;
		delete temp;
		if (isEmpty()) last = NULL;
		return temp_data;
	}
	T pop_back() {
		if (size == 1) return pop_front();
		if (isEmpty()) throw std::runtime_error("Empty List");
		size--;
		T temp_data = last->data;
		Node * temp = first;
		while (temp->next != last) temp = temp->next;
		last = temp;
		delete last->next;
		last->next = NULL;
		return temp_data;
	}
	T remove_at(size_t index) {
		if (index >= size) throw std::invalid_argument("Invalid Index");
		if (index == 0)	return pop_front();
		if (index == size - 1)	return pop_back();
		Node * temp = first;
		while (--index) temp = temp->next;
		Node * del_node = temp->next;
		T temp_data = del_node->data;
		temp->next = del_node->next;
		delete del_node;
		return temp_data;
	}
	int remove(const T& ELEMENT) {
		int count = 0;
		while (contains(ELEMENT)) {
			remove_at(indexOf(ELEMENT));
			count++;
		}
		return count;
	}
	void remove_duplicates() {
		int index = 0;
		std::set<T> lookup;
		Node *temp = first, *next;
		while (temp != NULL) {
			next = temp->next;
			if (lookup.count(temp->data)) {
				remove_at(index);
			} else {
				lookup.insert(temp->data);
				index++;
			}
			temp = next;
		}
		return;
	}
	const T& peak_first() const {
		if (isEmpty()) throw std::runtime_error("Empty List");
		return first->data;
	}
	const T& peak_last() const {
		if (isEmpty()) throw std::runtime_error("Empty List");
		return last->data;
	}
	// Indexing Operator
	T& operator[](size_t index) {
		if (index >= size) throw std::invalid_argument("Invalid Index");
		Node *temp = first;
		while (index--) temp = temp->next;
		return temp->data;
	}
	// Indexing Operator
	const T& operator[](size_t index) const {
		if (index >= size) throw std::invalid_argument("Invalid Index");
		Node *temp = first;
		while (index--) temp = temp->next;
		return temp->data;
	}
	// Reverse the link list
	void reverse() {
		Node *current = first, *next, *previous = NULL;
		while (current != NULL) {
			// Update the Next
			next = current->next;
			// Reverse the forward link of current node
			current->next = previous;
			// update current and previous
			previous = current;
			current = next;
		}
		// swap first and last
		// last = first;
		// first = previous;
		std::swap(last, first);
		return;
	}
	int indexOf(const T& ELEMENT) const {
		int index = 0;
		Node* temp = first;
		while (temp != nullptr) {
			if (temp->data == ELEMENT)
				return index;
			index++;
			temp = temp->next;
		}
		return -1;
	}
	bool contains(const T& ELEMENT) const {	return indexOf(ELEMENT) != -1;}

private:
	// Sort

	Node* _split(Node* head) {
		Node *fast = head, *slow = head;

		while (fast->next != NULL and fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;
		return fast;
	}

	Node* _merge(Node* first, Node* second) {
		Node dummy;
		Node* last = &dummy;
		while (first != NULL and second != NULL) {
			if (first->data < second->data) {
				last->next = first;
				last = first;
				first = first->next;
			}	else {
				last->next = second;
				last = second;
				second = second->next;
			}
		}

		while (first != NULL) {
			last->next = first;
			last = first;
			first = first->next;
		}

		while (second != NULL) {
			last->next = second;
			last = second;
			second = second->next;
		}

		this->last = last;
		return dummy.next;
	}

	Node* merge_sort(Node* head) {
		// Base Case
		if (head == NULL or head->next == NULL)	return head;
		// Recursive case
		// split the list in two halves
		Node* second = _split(head);

		// Call Merge Sort on both Halves
		head = merge_sort(head);
		second = merge_sort(second);

		// merge the two sorted halves in one list
		return _merge(head, second);
	}

public:
	void sort() {
		first = merge_sort(first);
		return;
	}
	// print function
	friend std::ostream& operator <<(std::ostream& out, const Linked_List<T>& head) {
		Node* temp = head.first;
		while (temp != NULL) {
			out << temp->data << ' ';
			temp = temp->next;
		}
		return out;
	}

};

int main() {
	Linked_List<std::string> list;
	list.push_back("Mason");
	list.push_back("Mason");
	list.push_back("Mason");
	list.push_back("MacTavish");
	list.push_back("MacTavish");
	list.push_front("Yuri");
	list.insert_at(2, "Makarov");
	std::cout << list << '\n';
	list.pop_front();
	std::cout << list << '\n';
	list.pop_back();
	std::cout << list << '\n';
	list.remove_at(1);
	std::cout << list << '\n';
	list[1] = "Menendez";
	std::cout << list[1] << '\n';
	list.push_front("Kratos");
	list.push_front("N.Drake");
	list.push_front("Kyyubi");
	list.push_front("Price");
	std::cout << list << '\n';
	list.reverse();
	std::cout << list << '\n';
	list.reverse();
	list.remove_duplicates();
	std::cout << list << '\n';

	Linked_List<int> list_int;
	list_int.push_front(43);
	list_int.push_front(47);
	list_int.push_front(49);
	list_int.push_front(99);
	list_int.push_front(99);
	list_int.push_front(99);
	std::cout << list_int << '\n';
	list_int.sort();
	std::cout << list_int << '\n';
	std::cout << list_int.contains(99) << '\n';
	std::cout << list_int.contains(69) << '\n';
	list_int.remove(99); // Will remove all ocurrences of the element if exists.
	std::cout << list_int << '\n';

	return 0;
}