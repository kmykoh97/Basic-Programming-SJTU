#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <typename T>
struct Node
{
    T data;
    shared_ptr<Node> next;
    Node(T d, shared_ptr<Node> n) : data(d), next(n) {}
};

// Template Stack
// Note: T type is used to set the Node type
template <typename T>
class Stack {
private:
    shared_ptr<Node<T>> head;
public:
    Stack() : head(NULL) {}
    Stack(const Stack<T> &rhs) = delete;
    Stack& operator=(const Stack<T> &rhs) = delete;
    void push(const T&);
    void pop();
    T top() const;
    void print() const;
};

// Notice <T> after the class name, it is the syntax requirement
template <typename T>
void Stack<T>::push(const T &data) {
    shared_ptr<Node<T>> temp = make_shared<Node<T>>(data,nullptr);
    if (head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

template <typename T>
void Stack<T>::pop() {
    //shared_ptr<Node<T>> temp = head;
    head = head->next;
}

template <typename T>
T Stack<T>::top() const {
    return head->data;
}

template <typename T>
void Stack<T>::print() const {
    // shared_ptr<Node<T>> temp;
    for (auto temp = head; temp != nullptr; temp = temp->next)
        cout << temp->data << '\n';
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