#include <iostream>
#include <stack>
#include <string>

using namespace std;

// check if both characters are a pair
bool isPair (char first, char second)
{
    if (first == '(' && second == ')') {
        return true;
    } else if (first == '{' && second == '}') {
        return true;
    } else if (first == '[' && second == ']') {
        return true;
    }

    return false; // if above condition not met, return false
}

// use stack to check if closing brackets are next to those in stack.top()
bool bracketChecker (string s)
{
    stack<char> Stack;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            Stack.push(s[i]);
        }

        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (Stack.empty() || !isPair(Stack.top(), s[i])) {
                return false;
            } else {
                Stack.pop();
            }
        }
    }

    // check if final stack is empty
    if (Stack.empty()) {
        return true; // empty
    }

    return false; // not empty
}

int main()
{
    string expression;
    getline(cin, expression);

    if (bracketChecker(expression)) {
        cout << "correct brackets!";
    } else {
        cout << "wrong brackets placement!";
    }

    system("pause");
    return 0;
}