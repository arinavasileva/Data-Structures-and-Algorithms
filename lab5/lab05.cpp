#include <iostream>

template <class T>
class Queue {
private:
    T* array;
    int capacity;
    int number_of_items;

public:
    Queue();
    ~Queue();
    bool enqueue(T item);
    bool dequeue(T& item);
    void print();
};

template <class T>
Queue<T>::Queue() {
    capacity = 5; // Initial capacity
    array = new T[capacity];
    number_of_items = 0;
}

template <class T>
Queue<T>::~Queue() {
    delete[] array;
}

template <class T>
bool Queue<T>::enqueue(T item) {
    if (number_of_items >= capacity) {
        // Increase capacity by 5 
        capacity += 5;
        // Create a new array with larger size
        T* new_array = new T[capacity];
        // Copy elements from the old array to the new one
        for (int i = 0; i < number_of_items; ++i) {
            new_array[i] = array[i];
        }
        // Releasing memory of the old array
        delete[] array;
        // Updating array pointer to point to the new array
        array = new_array;
        // Output message indicating size increase
        std::cout << "Size is increased and is now " << capacity << " items\n";
    }
    array[number_of_items++] = item;
    return true;
}

template <class T>
bool Queue<T>::dequeue(T& item) {
    if (number_of_items == 0)
        return false;
    else {
        item = array[0];
        for (int i = 0; i < number_of_items - 1; i++)
            array[i] = array[i + 1];
        number_of_items--;
        return true;
    }
}

template <class T>
void Queue<T>::print() {
    std::cout << "\nQueue now: \n\n";
    for (int i = 0; i < number_of_items; i++) {
        std::cout << " " << array[i] << "";
    }
    std::cout << "\n\n";
}

// Test program remains the same
int main() {
    Queue<char> queue;
    bool succeed;
    char chr;

    std::cout << "\nEnter a letter to be queued ";
    std::cout << "\nor digit 1 to dequeue a letter";
    std::cout << "\nor Return to quit a program\n";

    chr = std::cin.get();
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
            succeed = queue.enqueue(chr);
            queue.print();
            if (!succeed)
                printf("\n Enqueue operation failed\n");
        }
        if (chr == '1') {
            succeed = queue.dequeue(chr);
            if (succeed) {
                std::cout << "\na letter dequeued " << chr << " ";
                queue.print();
            } else
                std::cout << "\nDequeue operation failed\n ";
        }
        chr = std::cin.get();
    }

    return 0;
}

