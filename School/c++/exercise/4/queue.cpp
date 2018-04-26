#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

template <typename T>
void print (queue<T>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

// first way to reverse
template <typename T>
void reverseQueue (queue<T> & Queue)
{
    stack<T> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

// second way to reverse (recursive)
template <typename T>
void reverseQueue2 (queue<T> & Queue)
{
    if (Queue.empty())
        return;

    T data = Queue.front();
    Queue.pop();
    reverseQueue2(Queue);
    Queue.push(data);
}

int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    reverseQueue(Queue); // first way
    reverseQueue2(Queue); // second way
    print(Queue);

    system("pause");
    return 0;
}