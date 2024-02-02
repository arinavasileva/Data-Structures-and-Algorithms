#include <iostream>
#include <cctype> // for isdigit
using namespace std;

#define MAXN 5

template <class T>
class Stack {
private:
    T array[MAXN];
    int top;

public:
    Stack();
    bool push(T item);
    bool pop(T &item);
    void print();
};

// Implementations of operation functions
template <class T>
Stack<T>::Stack() {
    top = -1;
}

template <class T>
bool Stack<T>::push(T item) {
    if (top >= MAXN - 1)
        return false;
    else {
        array[++top] = item;
        return true;
    }
}

template <class T>
bool Stack<T>::pop(T &item) {
    if (top == -1)
        return false;
    else {
        item = array[top--];
        return true;
    }
}

template <class T>
void Stack<T>::print() {
    int i;

    cout << "\nStack is : ";
    for (i = top; i >= 0; i--)
        cout << array[i] << endl;

    cout << endl;
}

int main() {
    Stack<int> stack;
    char input;
    int operand, result;

    cout << "This is a RPN calculator. Enter operands and operators:" << endl;

    do {
        cin >> input;

        if (isdigit(input)) {
            operand = input - '0';
            stack.push(operand);
        } else {
            switch (input) {
                case '+':
                    if (stack.pop(operand)) {
                        result = stack.pop(operand) + operand;
                        stack.push(result);
                    } else {
                        cout << "Error: Insufficient operands for addition." << endl;
                        return 1;
                    }
                    break;
                case '-':
                    if (stack.pop(operand)) {
                        result = stack.pop(operand) - operand;
                        stack.push(result);
                    } else {
                        cout << "Error: Insufficient operands for subtraction." << endl;
                        return 1;
                    }
                    break;
                case '=':
                    if (stack.pop(result)) {
                        cout << "Top value is " << result << endl;
                        stack.push(result);
                    } else {
                        cout << "Error: Stack is empty." << endl;
                        return 1;
                    }
                    break;
                case 'Q':
                    stack.print();
                    return 0;
                default:
                    cout << "Error: Invalid input." << endl;
                    return 1;
            }
        }

    } while (input != 'Q');

    return 0;
}

