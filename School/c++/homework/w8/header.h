#include <iostream>
#include <vector>

using namespace std;

class List
{
    public:
    List(int* arr, int array_size);
    int length() const;
    bool insert(int pos, int value);
    int find(int pos, int value);
    int remove(int value);
    bool split(int pos, List& new_list);
    void combine(List& append_list);
    void print();

    private:
    Node* head; // head of the list
    int size; // current length of list
};

struct Node
{
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {}
};