#include "calculatorHeader.h"

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
                /* if putBack not called, need 2x ';' to show result */
                ts.putBack(t);  // if no '+' or '-' sign, put the token to buffer in class tokenStream() to access later
                return left;
        }
    }

    return left; // return result
}