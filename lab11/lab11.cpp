#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Node structure for the binary search tree
template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary search tree class
template<typename T>
class BinSTree {
public:
    BinSTree() : root(nullptr), comparisons(0) {}
    ~BinSTree() { clear(root); }
    
    void insert_to_tree(const T& value);
    bool isInTree(const T& value);

private:
    Node<T>* root;
    int comparisons;

    void clear(Node<T>* node);
    void insert_to_tree(Node<T>*& node, const T& value);
    bool isInTree(Node<T>* node, const T& value);
};

template<typename T>
void BinSTree<T>::clear(Node<T>* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
void BinSTree<T>::insert_to_tree(const T& value) {
    insert_to_tree(root, value);
}

template<typename T>
void BinSTree<T>::insert_to_tree(Node<T>*& node, const T& value) {
    if (!node) {
        node = new Node<T>(value);
        return;
    }

    if (value < node->data) {
        insert_to_tree(node->left, value);
    } else {
        insert_to_tree(node->right, value);
    }
}

template<typename T>
bool BinSTree<T>::isInTree(const T& value) {
    comparisons = 0;
    return isInTree(root, value);
}

template<typename T>
bool BinSTree<T>::isInTree(Node<T>* node, const T& value) {
    if (!node) {
        cout << "Number of comparisons: " << comparisons << endl;
        return false;
    }

    comparisons++;
    if (value == node->data) {
        cout << "Number of comparisons: " << comparisons << endl;
        return true;
    } else if (value < node->data) {
        return isInTree(node->left, value);
    } else {
        return isInTree(node->right, value);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    // Create and populate the binary search tree with 10,000 random numbers
    BinSTree<int> tree;
    for (int i = 0; i < 10000; ++i) {
        tree.insert_to_tree(rand() % 10000); // generates a random number between 0 – 9999
    }

    // Interactive loop for searching numbers in the tree
    while (true) {
        int num;
        cout << "Enter a number to search (-1 to exit): ";
        cin >> num;
        if (num == -1) break;
        bool found = tree.isInTree(num);
        if (found) {
            cout << num << " is in the tree." << endl;
        } else {
            cout << num << " is not in the tree." << endl;
        }
    }

    return 0;
}

