#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProductTriplet(vector <int> v1)
{
    int first, second;
    
    sort(v1.begin(), v1.end()); // sort the vector in accending order

    first = v1[v1.size()-1] * v1[v1.size()-2] * v1[v1.size()-3]; // last 3
    second = v1[0] * v1[1] * v1[v1.size()-1]; // first 2 & last 1

    // return bigger value
    if (first >= second) {
        return first;
    } else {
        return second;
    }
}

int main()
{
    // declarations
    vector <int> v1;
    int temp, maxAnswer;

    while (cin) {
        cin >> temp;
        v1.push_back(temp);
    }

    maxAnswer = maxProductTriplet(v1);

    cout << maxAnswer << endl; // print answer

    system("pause"); // to show result
    return 0;
}