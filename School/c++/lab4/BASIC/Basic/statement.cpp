/*
 * File: statement.cpp
 * -------------------
 * This file implements the constructor and destructor for
 * the Statement class itself.  Your implementation must do
 * the same for the subclasses you define for each of the
 * BASIC statements.
 */

#include <string>
#include "statement.h"
using namespace std;

/* Implementation of the Statement class */

Statement::Statement() {
   /* Empty */
}

Statement::~Statement() {
   /* Empty */
}

REM::REM(TokenScanner& scanner)
{
    // nothing to do as it is comment
}

void REM::execute(EvalState& state)
{
    // nothing to do as it is comment
}

LET::LET(TokenScanner& scanner)
{
    variableName = scanner.nextToken(); // store variable name
    
    if (scanner.nextToken() != "=") {
        error(); // wrong syntax
    }

    rhs = readE(scanner, 0); // create an expression parser tree

    if (scanner.hasMoreTokens()) {
        error();
    }
}

LET::~LET()
{
    delete rhs;
}

void LET::execute(EvalState& state)
{
    int value = rhs -> eval(state); // get the value of rhs expression
    state.setValue(variableName, value); // add element to map
}

PRINT::PRINT(TokenScanner& scanner)
{
    printStatement = readE(scanner, 0); // create an expression parser tree

    if (scanner.hasMoreTokens()) {
        error();
    }
}

PRINT::~PRINT()
{
    delete printStatement;
}

void PRINT::execute(EvalState& state)
{
    cout << printStatement -> eval(state) << endl; // print the value
}

INPUT::INPUT(TokenScanner& scanner)
{
    variableName = scanner.nextToken();

    if (scanner.hasMoreTokens()) {
        error();
    }
}

void INPUT::execute(EvalState& state)
{
    string prompt = getLine("?");
    state.setValue(variableName, stringToInteger(prompt)); // getLine can only get string so need to convert to integer
}

END::END(TokenScanner& scanner)
{
    // ending statement, nothing to do
}

void END::execute(EvalState& state)
{
    // state
}

GOTO::GOTO(TokenScanner& scanner)
{
    string token = scanner.nextToken(); // attempt to get line number

    TokenType type = scanner.getTokenType(token); // check the type of token got

    if (type != NUMBER) {
        error();
    } else {
        line = stringToInteger(token);
    }

    if (scanner.hasMoreTokens()) {
        error();
    }
}

void GOTO::execute(EvalState& state)
{
    // set the current line to line
}

IF::IF(TokenScanner& scanner)
{
    
}