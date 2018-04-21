#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {} // constructor
};

class List
{
    public:
    List(int* arr, int array_size); // constructor
    List();
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