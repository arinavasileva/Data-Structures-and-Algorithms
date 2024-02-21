#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& d, Node* n = NULL, Node* p = NULL) : data(d), next(n), prev(p) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(NULL), tail(NULL) {}

    void insert_to_front(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_to_back(const T& data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() const {
        Node* current = head;
        std::cout << "List:";
        while (current) {
            std::cout << " " << current->data;
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_reverse() const {
        Node* current = tail;
        std::cout << "List:";
        while (current) {
            std::cout << " " << current->data;
            current = current->prev;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
    }
};

int main() {
    LinkedList<int> dbl;
    dbl.print();
    dbl.print_reverse();
    dbl.insert_to_back(10);
    dbl.print();
    dbl.print_reverse();
    dbl.insert_to_front(20);
    dbl.print();
    dbl.print_reverse();
    dbl.insert_to_back(30);
    dbl.print();
    dbl.print_reverse();
    dbl.insert_to_front(40);
    dbl.print();
    dbl.print_reverse();
    dbl.insert_to_back(50);
    dbl.print();
    dbl.print_reverse();
    return EXIT_SUCCESS;
}
