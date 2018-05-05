#ifndef PQUEUE_H
#define PQUEUE_H

#include <memory> // shared_ptr

using namespace std;

class badInput{}; // for error throwing

// Node for each linkedlist
template <typename T>
struct Node
{
    int priority;
    T data;
    shared_ptr<Node<T>> next; // next Node
    Node(T d, int pri) : data(d), priority(pri), next(NULL) {} // constructor
};

// container for priority queue
template <typename T>
class PriorityQueue
{
    public:
    PriorityQueue() : head(NULL) {} // empty constructor
    void enqueue(T value, int priority); // push items in
    T dequeue(); // pull items out
    PriorityQueue(const PriorityQueue<T>&) = delete; // prevent copying
    PriorityQueue& operator=(const PriorityQueue<T>&) = delete; // prevent reassigning

    private:
    shared_ptr<Node<T>> head; // first Node
};

template <typename T>
void PriorityQueue<T>::enqueue(T value, int priority)
{
    shared_ptr<Node<T>> insertData = make_shared<Node<T>>(value, priority); // make new Node
    shared_ptr<Node<T>> current = this -> head; // store current Node pointer
    shared_ptr<Node<T>> temp;

    if (head == NULL) { // if nothing in queue, initiate first Node
        head = insertData;
    } else if (this -> head -> priority > priority) { // if new node is most prioritised, insert as head
        insertData -> next = head;
        this -> head = insertData;
    } else { // if in between, do this
        // after first Node, before last Node
        while (insertData -> priority >= current -> priority && current -> next != nullptr) {
            current = current -> next;
        }

        // place as last Node(most unprioritised)
        if (insertData -> priority >= current -> priority) {
            current -> next = insertData;
            return; // prevent going through following codes below
        }

        // push in between, reorganise Nodes
        temp = current -> next;
        current -> next = insertData;
        current -> next -> next = temp;
    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    T store;
    
    if (head == nullptr) {
        throw badInput{}; // throw error to be caught by main()
    } else {
        store = head -> data; // store data before deleting
        head = head -> next;
    }

    return store; // return the data value
}

#endif