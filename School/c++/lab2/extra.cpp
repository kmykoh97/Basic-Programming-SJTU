#include "header.h"

// declare a global variable
stringstream ssexp;

// error handling
void error(string info)
{
    cerr << info << endl; // print errors
    throw badToken{}; // throwing exception
}

// function to determine if a number has decimal points
bool decimalsDetermine(double a)
{
    int copier = a; // copy the double x

    if (copier == a) {
        return false; // no decimal points
    } else {
        return true; // has decimal points
    }
}

// function to do calculations
double calculate(string s)
{
    ssexp << s;
    while (ssexp) {
        cout << prompt; // marker
        token t = ts.get(); // get the next token
        while (t.kind == print) {
            t = ts.get(); // eats repeated ';'
        }
        if (t.kind == quit) {
            exit(0); // indicating success
        }
        ts.putBack(t);
        ANS = expression();
        // cout << result << ANS << endl; // to show result
        return ANS;
    }
}
