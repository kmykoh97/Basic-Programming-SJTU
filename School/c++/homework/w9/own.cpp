#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node* next;
    Node(T v) : value(v), next(NULL) {} // constructor
};

template <typename T>
class Stack
{
    Node<T>* head;
    T size;

    public:
    Stack() : head(NULL) {} // empty constructor
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    void push(T elem);
    bool pop(T& cell);
    void print();
};

template <typename T>
void Stack::push (T elem)
{
    T* smartPointer = elem;

    if (head == NULL) {
        head = smartPointer;
    } else {
        smartPointer -> next = head;
        head = smartPointer;
    }
}

template <typename T>
bool Stack::pop (T& cell)
{
    if (size > 0) {
        head = head -> next;
        return true;
    } else {
        return false;
    }
}

template <typename T>
void Stack::print() const {
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