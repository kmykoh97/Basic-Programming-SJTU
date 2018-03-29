#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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
      void restart(); // to restart the main() when called
      void putBack(token t); // place a token to buffer

    private:
      bool full {false}; // determine whether the buffer has been filled
      token buffer; // allocate a memmory to store unused and returned token
};

// empty error type to be caught by main()
struct badToken{};

extern tokenStream ts;
extern double ANS;

#endif