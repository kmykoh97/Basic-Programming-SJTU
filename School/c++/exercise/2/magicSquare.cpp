#include <iostream>
#include <vector>

using namespace std;


vector< vector<int> > magicSquareFill (vector< vector<int> > v1, int n)
{
    int x, y, row, col;

    // initialise the position to the center top
    x = 0;
    y = n / 2;

    // fill in the vector
    for (int i = 1; i <= n * n; i++) {
        v1[x][y] = i;
        // find the next cell in top right
        row = (x - 1 + n) % n;
        col = (y + 1) % n;
        if (v1[row][col] == 0) {
            x = row;
            y = col;
        } else { // if filled, use the row below it
            x = (row + 2) % n;
        }
        
    }

    return v1;
}

void printMagicSquare(vector< vector<int> > v1, int n)
{
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << v1[x][y] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n;

    // prompt for input of size of Magic Square
    do {
        cout << "please insert odd integer order of magic square: ";
        cin >> n;
        cout << endl;
        if (n % 2 == 0) {
            cout << "please insert odd integer only!" << endl;
        }
    } while (n % 2 == 0);

    // create a vector to hold matrices
    vector< vector<int> > v1(n, vector<int>(n));

    // initialise the elements of vector v1 with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1[i][j] = 0;
        }
    }

    v1 = magicSquareFill(v1, n);
    printMagicSquare(v1, n);
    
    system("pause");
    return 0;
}