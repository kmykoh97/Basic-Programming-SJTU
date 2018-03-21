/* Calculator by Meng Yit Koh
517030990022
Shanghai Jiao Tong University */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// do some definitions and declarations here
const string prompt = "> ";
const string result = "= ";
const char number = '8';
const char quit = 'q';
const char print = ';';

double primary();
double term();
double expression();
double factorial(double a);
bool decimalsDetermine(double a);
void error(string info);
void calculate();

double ANS = 0; // to store ANS

// make a new type of token
struct token
{
    char kind; // store the type of token
    double value; // store the value of token if the kind is a number
};

// empty error type to be caught by main()
struct badToken{};

// make a new class to get, return or store returned token
class tokenStream
{
    public:
      token get(); // get a token from expression if there is nothing in buffer. Else,
      void restart(); // to restart the main() when called
      void putBack(token t); // place a token to buffer

    private:
      bool full {false}; // determine whether the buffer has been filled
      token buffer; // allocate a memmory to store unused and returned token
};

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

// check for brackets, do positive/negative, factorial in some cases or return values
double primary()
{
    token t = ts.get(); // get the next token

    switch (t.kind) {
        case '(': case ')': // perform operations inside bracket
            {
                double insideBracket = expression();
                t = ts.get();
                if (t.kind != ')') {
                    error("error"); // no close bracket found
                }
                return insideBracket;
            }
        case number: // in case of number found
            {
                double temp = t.value;
                t = ts.get();
                if (t.kind == '!') { // do factorial when there are multiple brackets
                    temp = factorial(temp);
                } else {
                    ts.putBack(t);
                }
                return temp;
            }
        case '-': // negative case
            return -primary();
        case '+': // positive case
            return primary();
        default: // in case of special symbols found
            error("error"); // special symbols not allowed
    }
}

// perform multiplication and division. Perform primary()
double term()
{
    double left = primary(); // get numbers from primary()

    // keep doing multiplications and divisions until no '*' and '/' left
    while (true) {
        token t = ts.get(); // get the next token

        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
                {
                    double temp = primary();
			        if (temp == 0.0) {
                        error("error"); // zero error
                    }
			        left /= temp;
			        break;
                }
            case '%':
                {
                    double temp = primary();
                    if (temp == 0) {
                        error("error"); // zero error
                    }
                    if (decimalsDetermine(temp) || decimalsDetermine(left)) {
                        error("error"); // cannot be decimal points
                    }
                    left = fmod(left, temp); // peforming modulus
                    break;
                }
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
        token t = ts.get(); // get the next token

        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            case '!':
                return factorial(left);
            default:
                /* if putBack not called, need 2x ';' to show result */
                ts.putBack(t); // if no '+' or '-' sign, put the token to buffer in class tokenStream() to access later
                return left;
        }
    }

    return left; // return result
}

// function to perform factorial '!'
double factorial (double a)
{
    if (decimalsDetermine(a)) { // error if factorial is a decimal
        error("error"); // factorial cannot has decimals
    } else if (a < 0) { // error if factorial is negative number
        error("error"); // factorial cannot be negative
    } else if (a == 1 || a == 0) {
        return 1;
    }
    
    return a * factorial(a-1); // recursive way to get factorial
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

// error handling
void error(string info)
{
    cerr << info << endl; // print errors
    throw badToken{}; // throwing exception
}

// function to do calculations
void calculate()
{
    while (cin) {
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
        cout << result << ANS << endl; // to show result
    }
}

int main()
{
    // cout << "This is a command line calculator to do +-*/%!" << endl;

    try {
        calculate(); // do main calculation
    }

    // catch all errors returned by function error()
    catch (badToken) {
        ts.restart(); // clear unwanted memories
        main(); // restart when error catched
    }

    catch (...) {
        exit(1); // indicating failure
    }

    system("pause"); // to show result
    // return 0; // indicating success
}