#include <iostream>
#include<string>

using namespace std;

// make a new type of token
class token
{
    public:
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

void error(string info);

double primary();
double term();
double expression();

extern tokenStream ts;