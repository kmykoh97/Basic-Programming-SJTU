#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>
// #include <string> // uncomment to use string type

using namespace std;

template <typename T>
struct Node
{
    T value;
    shared_ptr<Node> next;
    Node(T v) : value(v), next(NULL) {} // constructor
};

template <typename T>
class Stack
{
    private:
    shared_ptr<Node<T>> head;

    public:
    Stack() : head(NULL) {} // empty constructor
    Stack(const Stack<T>&) = delete; // prevent copying
    Stack& operator=(const Stack<T>&) = delete; // prevent reassigning
    void push(T elem); // to push elem to stack
    bool pop(T& cell); // to remove item from stack and give the value to cell
    // void print() const; // to print items
};

// methods implementation
template <typename T>
void Stack<T>::push (T elem)
{
    shared_ptr<Node<T>> tempPtr = make_shared<Node<T>>(elem); // smart pointer

    if (head == NULL) {
        head = tempPtr;
    } else {
        tempPtr -> next = head;
        head = tempPtr; // make the new Node becomes head
    }
}

template <typename T>
bool Stack<T>::pop (T& cell)
{
    if (head == nullptr) {
        return false;
    } else {
        cell = head -> value; // give value to cell before deleting
        head = head -> next;
    }

    return true;
}

// method to print items in stack (uncomment to use)
/*
template <typename T>
void Stack<T>::print() const
{
    for (auto temp = head; temp != nullptr; temp = temp -> next) {
        cout << temp -> value << endl;
    }
}
*/

#endif