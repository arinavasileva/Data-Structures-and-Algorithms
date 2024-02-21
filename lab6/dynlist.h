/* dynlist.h -- Dynamic linked linear list */
#include <iostream>

// Interface of list
template <class T>
class LinkedList {
private:
	// definition of the list node class
	class Node {
	public:
		T     _value;	// data
		Node *_pNext;	// pointer to the next node
		Node() : _pNext(NULL) {}
		Node(T val) : _value(val), _pNext(NULL) {}
		Node(T val, Node* next) : _value(val), _pNext(next) {}
	};

	Node *first;


public:
	LinkedList();
	~LinkedList();
	LinkedList<T>& insert_to_end(T data);
	void print(std::ostream &out = std::cout) const;
};

// Implementation of list
template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node *aux1 = first;
	while (aux1 != nullptr) {
			Node *aux2 = aux1->_pNext;
			delete aux1;
	    printf("\nDeleted"); //for testing purposes
	    aux1 = aux2;
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::insert_to_end(T data) {
	Node *newnode = new Node(data);
	if (first == NULL)
			first = newnode;        //first node
	else {
			Node *current = first;
			while (current->_pNext != NULL) {
					current = current->_pNext;
			}
			current->_pNext = newnode;
	}

	return *this;
}

template <class T>
void LinkedList<T>::print(std::ostream &out = std::cout) const {
    Node *what = first;

    out << "\nList:";
    what = first;
    while (what != NULL) {
	    out << " " << what->_value << " ";
	    what = what->_pNext;
    }
	out << endl;
}

template <class T>
std::ostream &operator<<(std::ostream &out,  LinkedList<T> const &data) {
	data.print(out);
	return out;
}
