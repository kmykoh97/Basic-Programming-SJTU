// Program to find non-duplicate in given list
// Created by MyKoh
// 2018-03-06

#include <iostream>
#include <vector> // to create vector and use functions related

using namespace std;

bool compareVector(int a, vector<int> b)
{
    // return counts of objects
    int count = 0;
    for (int i = 0; i < b.size(); i++) {
        if (a == b[i]) {
            ++count;
        }
    }

    // return true for non-duplicate, return false for duplicates
    if (count == 1) {
        return true;
    } else if (count == 2) {
        return false;
    }
}

int main()
{
    int a, b; // variables init

    do { // if user inputs even number as first variable(a), loops again
        cout << "Please insert number of elements and those elements in the array: ";
        cin >> a;
    } while (a % 2 == 0);

    // inits a vector and fill them with inputs
    vector <int> v1(a);
    for (int i = 0; i < a; i++) {
        cin >> b;
        v1[i] = b;
    }

    // for loop to use the compareVector() function
    for (int i = 0; i < v1.size(); i++) {
        if (compareVector(v1[i], v1)) {
            cout << v1[i] << endl;
            break;
        }
    }

    system("pause"); // to show results

    return 0;
}