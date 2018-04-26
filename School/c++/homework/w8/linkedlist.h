#include <iostream>

using namespace std;

// ----------------METHOD DECLARATIONS------------------
// structure for each node in linked list
struct Node
{
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {} // constructor
};

// class for linked list
class List
{
    public:
    List(int* arr, int array_size); // constructor
    List(); // second constructor
    int length() const;
    bool insert(int pos, int value);
    int find(int pos, int value);
    int remove(int value);
    bool split(int pos, List& new_list);
    void combine(List& append_list);
    void print();   
    ~List(); // destructor

    private:
    Node* head; // head of list
    int size; // current length
};

// ----------------METHOD IMPLEMENTATION------------------
// constructor
List::List(int* arr, int array_size)
{
    // size initialization
    size = array_size;

    // initialize new node for head
    this -> head = new Node(arr[0]);
    Node* temp = this -> head; // variable to store current node

    // create subsequence nodes
    for (int i = 1; i < size; i++) {
        Node* node = new Node(arr[i]);
        temp -> next = node;
        temp = node;
    }
}

// empty constructor
List::List()
{
    this -> head = NULL;
    this -> size = 0;
}

// destructor
List::~List()
{
    // declarations
    Node* first = this -> head;
    Node* second = first -> next;

    // free memory
    for (int i = 0; i < size; i++) {
        delete first;
        first = second;
        second = first -> next;
    }
}

// to return length of current list
int List::length() const
{
    return size;
}

// insert new node in position pos of value value. Return true if success, return false if fail
bool List::insert(int pos, int value)
{
    if (0 <= pos < size) {
        // increase size value and create new array
        size++;

        Node* temp = this -> head;

        // loops to 
        for (int i = 1; i < pos; i++) {
            temp = temp -> next;
        }

        Node* temp2 = temp -> next;
        temp -> next = new Node(value);
        temp -> next -> next = temp2;

        return true;
    } else {
        return false;
    }
}

// find first node of value value start from given position inclusive
int List::find(int pos, int value)
{
    Node* temp = this -> head; // points to head
    int count = 0;

    // cursor temp to pos position
    for (int i = 0; i < pos; i++) {
        temp = temp -> next;
        count++;
    }

    // to return position of node
    for (int i = pos; i < size; i++) {
        if (temp -> value == value) {
            return count;
        }
        temp = temp -> next;
        count++;
    }

    return -1; // return -1 if no such node with value found
}

// remove all nodes with value value
int List::remove(int value)
{
    Node* temp = this -> head; // points to head
    int count = 0;

    // remove node from beginning of list
    while (temp -> value == value) {
        this -> head = temp -> next; // change head
        free(temp); // free old head node
        temp = this -> head;
        count++;
        size--; // decrease size
    }
    
    // remove node from consequents of list
    Node* prev = this -> head;
    temp = prev -> next;
    while (temp != NULL) {
        if (temp -> value == value) {
            prev -> next = temp -> next;
            free(temp); // free memory
            prev = prev -> next;
            temp = prev -> next;
            count++;
            size--;
        } else {
            prev = prev -> next;
            temp = prev -> next;
        }
    }

    return count;
}

bool List::split(int pos, List& new_list)
{
    // determine new_list size
    if (new_list.size != 0) {
        return false;
    }

    // determine range of pos
    if (!(0 <= pos < size)) {
        return false;
    }
    
    Node* temp = this -> head;
    
    // loop temp to position pos
    for (int i = 0; i < pos; i++) {
        temp = temp -> next;
    }

    // modifies new_list attributes
    new_list.head = temp -> next;
    new_list.size = this -> size - (pos + 1);
    this -> size = pos + 1;

    return true;
}

void List::combine(List& append_list)
{
    // size = this -> size + append_list -> size;
    Node* temp = this -> head;

    // loop to last of nodes list
    for (int i = 1; i < size + append_list.size; i++) {
        temp = temp -> next;
    }
    
    // combine nodes
    temp -> next = append_list.head;
    size += append_list.size;
    append_list.size = 0;
}

void List::print()
{
    Node* current = this -> head; // initialisation with head

    // loop through to print all nodes' value
    for (int i = 0; i < size; i++) {
        cout << current -> value << " ";
        current = current -> next;
    }
    cout << endl;
}