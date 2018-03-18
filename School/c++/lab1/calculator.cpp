#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// do some definitions here
void calculate();
double expression();
bool decimalsDetermine(double x);
double term();
double primary();
int factorial(int a);
void cleanUp();
void error(string info);
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
int main();

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
      void restart();
      void putBack(token t); // place a token to buffer

    private:
      bool full {false}; // determine whether the buffer has been filled
      token buffer; // allocate a memmory to store unused and returned token
};

tokenStream ts;

// error type
class badToken{
};

// error handling
void error(string info)
{
    cerr << info << endl;
    throw badToken{};
}



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
        default:
            error("invalid token");
    }
}

void tokenStream::restart()
{
    string temp;
    getline(cin, temp);
    if (temp.empty()) {
        return;
    }
    cin >> temp;
}

// check for brackets or return values
double primary()
{
    token t = ts.get(); // get the next token

    switch (t.kind) {
        case '(': case ')': // perform operations inside bracket
            {
                double insideBracket = expression();
                t = ts.get();
                if (t.kind != ')') {
                    error("no close bracket found");
                }
                return insideBracket;
            }
        case number: // in case of number found
            {
                double temp = t.value;
                t = ts.get();
                if (t.kind == '!') {
                    temp = factorial((int) temp);
                } else {
                    ts.putBack(t);
                }
                return temp;
            }
        case '-':
            return -primary();
        case '+':
            return primary();
        default: // in case of special symbols found
            error("special symbols not allowed");
    }

    // return t.value;
}

bool decimalsDetermine(double x)
{
    int copier = x;

    if (copier == x) {
        return false; // no decimal points
    } else {
        return true; // has decimal points
    }
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
                    double temp = primary();
			        if (temp == 0.0) {
                        error("zero error");
                    }
			        left /= temp;
			        break;
                }
            case '%':
                {
                    double temp = primary();
                    if (temp == 0) {
                        error("zero error");
                    }
                    if (decimalsDetermine(temp) || decimalsDetermine(left)) {
                        error("cannot be decimal points");
                    }
                    left = fmod(left, temp);
                    // t = ts.get();
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
        token t = ts.get();

        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            case '!':
                return factorial((int)left);
            default:
                /* if putBack not called, need 2x ';' to show result */
                ts.putBack(t); // if no '+' or '-' sign, put the token to buffer in class tokenStream() to access later
                // return primary();
                return left;
        }
    }

    return left; // return result
}

void calculate()
{
    while (cin) {
        try {
            cout << prompt;
            token t = ts.get();
            while (t.kind == print) {
                t = ts.get(); // eats ';'
            }
            if (t.kind == quit) {
                return;
            }
            ts.putBack(t);
            cout << result << expression() << endl;
        }

        catch (exception& e) {
            cerr << e.what() << endl;
        }
    }
}

int factorial (int a)
{
    if (a < 0) {
        error("cannot be negative factorial");
    }
    if (a == 1 || a == 0) {
        return 1;
    }
    
    return a * factorial(a-1);
}

// main execution
int main()
{
    try {
        calculate();
    }

    catch (badToken) {
        ts.restart();
        main();
    }

    system("pause");
    return 0;
}