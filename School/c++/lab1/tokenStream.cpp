#include "calculatorHeader.h"

tokenStream ts;

// define putBack method here
void tokenStream::putBack(token t)
{
    if (full) {
        error("putBack into full buffer");
    }

    buffer = t;
    full = true;
}

// define get method here
token tokenStream::get()
{
    // initialisation of variables
    char temp;
    double number;

    // get from buffer if there is something there
    if (full) {
        full = false;
        return buffer;
    }

    // if there is nothing in buffer, check for operators or doubles
    cin >> temp;
    switch(temp) {
        case '+': case '-': case '*': case '/': case '(': case ')': case 'q': case ';':
            return token{temp};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(temp); // put the char back into cin
            cin >> number; // get complete double from cin
            return token{'8', number}; // return a token with suitable attributes
        }
        default:
            error("invalid token");
    }
}