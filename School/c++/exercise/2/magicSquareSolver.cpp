#include <iostream>
#include <vector>

using namespace std;

bool checker (vector < vector<int> >& v1, int n)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v1[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

void solver1 (vector < vector<int> >& v1, int n)
{
    if (v1[0][1] != 0 && v1[1][0] != 0) {
        v1[2][2] = (v1[0][1] + v1[1][0]) / 2;
    }

    if (v1[0][1] != 0 && v1[1][2] != 0) {
        v1[2][0] = (v1[0][1] + v1[1][2]) / 2;
    }

    if (v1[2][1] != 0 && v1[1][0] != 0) {
        v1[0][2] = (v1[2][1] + v1[1][0]) / 2;
    }

    if (v1[2][1] != 0 && v1[1][2] != 0) {
        v1[0][0] = (v1[2][1] + v1[1][2]) / 2;
    }
}

void solver2 (vector < vector<int> >& v1, int n)
{
    if (v1[0][0] != 0 && v1[2][2] != 0) {
        v1[1][1] = (v1[0][0] + v1[2][2]) / 2;
        return;
    }

    if (v1[0][1] != 0 && v1[2][1] != 0) {
        v1[1][1] = (v1[0][1] + v1[2][1]) / 2;
        return;
    }

    if (v1[0][2] != 0 && v1[2][0] != 0) {
        v1[1][1] = (v1[0][2] + v1[2][0]) / 2;
        return;
    }

    if (v1[1][0] != 0 && v1[1][2] != 0) {
        v1[1][1] = (v1[1][0] + v1[1][2]) / 2;
        return;
    }
}

void solver3 (vector < vector<int> >& v1, int n)
{
    if (v1[1][1] != 0) {
        
        if (v1[0][0] != 0) {
            v1[2][2] = 2 * v1[1][1] - v1[0][0];
        } else if (v1[2][2] != 0) {
            v1[0][0] = 2 * v1[1][1] - v1[2][2];
        }

        if (v1[0][1] != 0) {
            v1[2][1] = 2 * v1[1][1] - v1[0][1];
        } else if (v1[2][1] != 0) {
            v1[0][1] = 2 * v1[1][1] - v1[2][1];
        }

        if (v1[0][2] != 0) {
            v1[2][0] = 2 * v1[1][1] - v1[0][2];
        } else if (v1[2][0] != 0) {
            v1[0][2] = 2 * v1[1][1] - v1[2][0];
        }

        if (v1[1][0] != 0) {
            v1[1][2] = 2 * v1[1][1] - v1[1][0];
        } else if (v1[1][2] != 0) {
            v1[1][0] = 2 * v1[1][1] - v1[1][2];
        }
    }
}

void solver4 (vector < vector<int> >& v1, int n)
{
    if (v1[0][0] != 0 && v1[0][2] != 0) {
        v1[2][1] = v1[0][0] + v1[0][2] - 5;
    }

    if (v1[0][0] != 0 && v1[2][0] != 0) {
        v1[1][2] = v1[0][0] + v1[2][0] - 5;
    }

    if (v1[2][0] != 0 && v1[2][2] != 0) {
        v1[0][1] = v1[2][0] + v1[2][2] - 5;
    }

    if (v1[0][2] != 0 && v1[2][2] != 0) {
        v1[1][0] = v1[0][2] + v1[2][2] - 5;
    }

    if (v1[0][0] != 0 && v1[1][2] != 0) {
        v1[2][0] = v1[1][2] - v1[0][0] + 5;
    }

    if (v1[0][0] != 0 && v1[2][1] != 0) {
        v1[0][2] = v1[2][1] - v1[0][0] + 5;
    }

    if (v1[0][2] != 0 && v1[1][0] != 0) {
        v1[2][2] = v1[1][0] - v1[0][2] + 5;
    }

    if (v1[0][2] != 0 && v1[2][1] != 0) {
        v1[0][0] = v1[2][1] - v1[0][2] + 5;
    }

    if (v1[2][0] != 0 && v1[0][1] != 0) {
        v1[2][2] = v1[0][1] - v1[2][0] + 5;
    }

    if (v1[2][0] != 0 && v1[1][2] != 0) {
        v1[0][0] = v1[1][2] - v1[2][0] + 5;
    }

    if (v1[2][2] != 0 && v1[1][0] != 0) {
        v1[0][2] = v1[1][0] - v1[2][2] + 5;
    }

    if (v1[2][2] != 0 && v1[0][1] != 0) {
        v1[2][0] = v1[0][1] - v1[2][2] + 5;
    }
}

void printMagicSquare(vector < vector<int> >& v1, int n)
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
    int n = 3; 

    // create a vector to hold matrices
    vector< vector<int> > v1(n, vector<int>(n));

    int i = 0;
    int j = 0;

    do {
        int temp;
        cin >> temp;
        v1[i][j] = temp;
        if (j < 2) {
            j++;
            continue;
        } else if (j == 2) {
            i++;
            j = 0;
            continue;
        }
    } while (i != 3);

    // v1 = magicSquareFill(v1, n);
    
    while (!checker(v1, n)) {
        solver1(v1, n);
        solver2(v1, n);
        solver3(v1, n);
        solver4(v1, n);
    }

    printMagicSquare(v1, n);
    
    system("pause");
    return 0;
}