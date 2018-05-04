#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    public:
    Matrix(int rowG, int colG, vector<int> &values); // constructor
    void transpose(); // method to perform transpose of matrix
    friend ostream& operator<< (ostream& out, Matrix &m); // declared friend to access private attributes
    
    private:
    vector<vector<int>> matrix; // storing matrix
    int row; // row of Matrix
    int col; // column of Matrix
};

void Matrix::transpose()
{
    vector<vector<int>> temp_vector(matrix[0].size(), vector<int>(matrix.size())); // declared a temporary vector of size: [col][row]

    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            temp_vector[i][j] = matrix[j][i];
        }
    }

    // follow up assignments
    int temp = row;
    row = col;
    col = temp;
    matrix.clear(); // reset original vector
    matrix = temp_vector;
}

// constructor
Matrix::Matrix(int rowG, int colG, vector<int> &values)
{
    row = rowG; // assignment of row
    col = colG; // assignment of col
    int counter = 0;
    vector<int> temp_vector(colG); // temporary vector to put_back() to matrix later

    for (int i = 0; i < rowG; i++) {
        matrix.push_back(temp_vector); // create new row
        for (int j = 0; j < colG; j++) {
            matrix[i][j] = values[counter];
            counter++;
        }
    }
}

// operator overloading
ostream& operator<< (ostream& out, Matrix &m)
{
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.col; j++) {
            out << m.matrix[i][j] << "  ";
        }
        out << endl;
    }

    return out;
}

int main()
{
    vector<int> test = {1, 2, 3, 5, 6, 8};
    Matrix m{2, 3, test};
    cout << m << endl;
    m.transpose();
    cout << m;

    system("pause"); // keep window opens
    return 0;
}