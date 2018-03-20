#include "calculatorHeader.h"

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