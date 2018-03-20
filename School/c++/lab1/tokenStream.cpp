#include "calculatorHeader.h"

// define get method here
token tokenStream::get()
{
    // initialisation of variables
    char temp;

    // get from buffer if there is something there
    if (full) {
        full = false;
        return buffer;
    }

    // if there is nothing in buffer, check for operators or doubles
    cin >> temp; // skips spaces
    switch(temp) {
        case '+': case '-':
        case '*': case '/':
        case '(': case ')':
        case quit: case print:
        case '%': case '!':
            return token{temp};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(temp); // put the char back into cin
                double value;
                cin >> value; // get complete double from cin
                return token{number, value}; // return a token with suitable attributes
            }
        case 'A':
            {
                cin.putback(temp);
                string ANSTest;
                cin >> setw(3) >> ANSTest;
                if (ANSTest == "ANS") {
                    return token{number, ANS};
                }
                // if (ANSTest.substr(0,3) == "ANS") {

                //     (ANSTest.substr(3, ANSTest.length()));
                //     cin.putback(after);
                //     return token{number, ANS};
                // }
                error("error"); // invalid token
            }
        default:
            error("error"); // invalid token
    }
}

// define restart method here
void tokenStream::restart()
{
    string temp; // string declaration

    // to read newline and ignore them
    while (true) {
        if (cin.get() == '\n') {
            return;
        }
    }

    // to read remaining strings and ignore them
    cin >> temp;
    this->full = false;
}

// define putBack method here
void tokenStream::putBack(token t)
{
    if (full) {
        error("error"); // putBack into full buffer
    }

    buffer = t;
    full = true;
}

tokenStream ts; // class declaration