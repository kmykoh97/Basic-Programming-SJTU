#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *next;
    Node(T v) : value(v), next(NULL) {} // constructor
};

template <typename T>
class Stack
{
    private:
    Node<T> *head;
    int size;

    public:
    Stack(); // empty constructor
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    ~Stack();
    void push(T elem);
    bool pop(/*T& cell*/);
    void print();
};

template <typename T>
Stack<T>::Stack()
{
    head = NULL;
    size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!isEmpty()) {
        pop();
    }
}



template <typename T>
void Stack<T>::push (T elem)
{
    Node<T>* smartPointer = new Node<T>(elem);

    if (head == NULL) {
        head = smartPointer;
    } else {
        smartPointer -> next = head;
        head = smartPointer;
    }

    size++;
}

template <typename T>
bool Stack<T>::pop (/*T& cell*/)
{
    if (size > 0) {
        head = head -> next;
        return true;
    } else {
        return false;
    }
}

bool isEmpty()
{
    return (size == 0);
}

template <typename T>
void Stack<T>::print() {
    for (T* temp = head; temp != nullptr; temp = temp -> next)
        cout << temp -> value << '\n';
}

int main()
{
    cout << "String data" << '\n';
    {
        Stack<string> strStack;
        strStack.push("Test1");
        strStack.push("Test2");
        strStack.push("Test3");
        strStack.print();
        strStack.pop();
        strStack.print();
    }
    cout << "Integer data" << '\n';
    {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.print();
        intStack.pop();
        intStack.print();
    }

    system("pause");
    return 0;
}