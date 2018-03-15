#include <iostream>
#include <vector>

using namespace std；



int main()
{
    int n = 3;

    // create a vector to hold matrices
    vector< vector<int> > v1(n, vector<int>(n));

    // initialise the elements of vector v1 with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1[i][j] = 0;
        }
    }


    return 0;
}