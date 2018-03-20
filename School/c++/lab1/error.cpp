#include"calculatorHeader.h"

// error handling
void error(string info)
{
    cerr << info << endl; // print errors
    throw badToken{}; // throwing exception
}