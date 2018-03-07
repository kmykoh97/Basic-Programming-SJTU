// Program to solve quadratic equation
// Created by MyKoh
// 2018-03-06

#include <iostream>
#include <cmath> // maths libraries ie: round, pow
#include <iomanip> // alters precision level

using namespace std;

void quadraticSolver(double a, double b, double c); // define a function in advance

// function to make sure datas introduced to quadraticSolver() function are of correct types
bool coefficientsFilter(double a, double b, double c)
{
    if (a == 0) {
        cout << "error";
        return false;
    } else {
        quadraticSolver(a, b, c);
        return true;
    }
}

// function to find roots of quadratic equation and prints them on screen with correct precision level
void quadraticSolver(double a, double b, double c) // code the function defined
{
    double cts, solution1, solution2;

    cts = pow(b, 2) - 4 * a * c;
    solution1 = ((-b + pow(cts, 0.5)) / (2 * a));
    solution2 = ((-b - pow(cts, 0.5)) / (2 * a));
    solution1 = round(solution1 * 100) / 100;
    solution2 = round(solution2 * 100) / 100;

    cout << fixed << setprecision(2); // set precision level
    if (cts < 0) {
        cout << "invalid" << endl;
    } else if (cts == 0) {
        cout << solution1 << endl;
    } else {
        cout << solution1 << " " << solution2 << endl;
    }
}

int main()
{
    double a, b, c;
    bool operationSuccess;

    do {
        // cout << "Please insert coefficients (a,b,c) separated by spaces: ";
        cin >> a >> b >> c;
        if (!cin) {
            cout << "error" << endl;
            break;
        } else {
            operationSuccess = coefficientsFilter(a, b, c);
        }
    } while (operationSuccess == false);
    // cout << a << b << c;
    
    system("pause"); // to show results

    return 0;
}