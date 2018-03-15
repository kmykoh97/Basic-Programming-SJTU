#include <iostream>
#include <vector>
#include <string>

using namespace std;

// error handling
void error(string info)
{
    cout << info << endl;
    // cerr << info << endl;
}

// make a new type of token
struct token
{
    char kind; // store the type of token
    double value; // store the value of token if the kind is a number
};

// make a new class to get, return or store returned token
class tokenStream
{
    public:
      token get(); // get a token from expression if there is nothing in buffer. Else, 
      void putBack(token); // place a token to buffer

    private:
      bool full {false}; // determine whether the buffer has been filled
      token buffer; // allocate a memmory to store unused and returned token
};

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

// do some init of class and function here
tokenStream ts;
double expression();

// check for brackets or return values
double primary()
{
    token t = ts.get(); // get the next token

    switch (t.kind) {
        case '(': // perform operations inside bracket
            {
                double insideBracket = expression();
                t = ts.get();
                if (t.kind != ')') {
                    error("no close bracket found");
                }
                return insideBracket;
            }
        case '8': // in case of number found
            return t.value;
        default: // in case of special symbols found
            error("primary expected");
    }

    // return t.value;
}

// perform multiplication and division. Perform primary()
double term()
{
    double left = primary(); // get numbers from primary()

    // keep doing multiplications and divisions until no '*' and '/' left
    while (true) {
        token t = ts.get();

        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {
                if (primary() == 0) {
                    error("zero error");
                } else {
                    left /= primary();
                } break;
            }
                break;
            default: 
                ts.putBack(t); // if no '*' or '/' sign, put the token to buffer in class tokenStream() to access later
                return left;
        }
    }

    return left; // return result
}

// perform addition and substraction. Perform term()
double expression()
{
    double left = term(); // get numbers from term()

    // keep doing additions and substractions until no '+' and '-' left
    while (true) {
        token t = ts.get();

        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                // ts.putBack(t);  // if no '+' or '-' sign, put the token to buffer in class tokenStream() to access later
                return left;
        }
    }

    return left; // return result
}

// main execution
int main()
{
    double answer = 0;
    while (cin) {
        token t = ts.get();
        if (t.kind == 'q') {
            break;
        } else if (t.kind == ';') {
            cout << answer << endl;
            break;
        } else {
            ts.putBack(t);
        }

        answer = expression();
    }

    system("pause"); // to view result

    return 0;
}