/*
 * File: statement.cpp
 * -------------------
 * This file implements the constructor and destructor for
 * the Statement class itself.  Your implementation must do
 * the same for the subclasses you define for each of the
 * BASIC statements.
 */

#include "statement.h"
#include <string>
#include "evalstate.h"
#include "exp.h"
#include "parser.h"
#include "../StanfordCPPLib/error.h"
#include "../StanfordCPPLib/tokenscanner.h"

using namespace std;

/* Implementation of the Statement class */

// cheack if the INPUT is valid integer
bool is_number(const string& s)
{
    return s.find_first_not_of("0123456789-") == string::npos;
}

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
        cout << "SYNTAX ERROR" << endl;
    }

    rhs = readE(scanner, 0); // create an expression parser tree

    if (scanner.hasMoreTokens()) {
        cout << "SYNTAX ERROR" << endl;
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
        cout << "SYNTAX ERROR" << endl;
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
        cout << "SYNTAX ERROR" << endl;
    }
}

void INPUT::execute(EvalState& state)
{
    string prompt = getLine(" ? ");
    while (!is_number(prompt)) {
        cout << "INVALID NUMBER" << endl;
        prompt = getLine(" ? ");
    }
    state.setValue(variableName, stringToInteger(prompt)); // getLine can only get string so need to convert to integer
}

END::END(TokenScanner& scanner)
{
    // ending statement, nothing to do
}

void END::execute(EvalState& state)
{
    state.setCurrentLine(-1);
}

GOTO::GOTO(TokenScanner& scanner)
{
    string token = scanner.nextToken(); // attempt to get line number

    TokenType type = scanner.getTokenType(token); // check the type of token got

    if (type != NUMBER) {
        cout << "INVALID SYNTAX" << endl;
    } else {
        line = stringToInteger(token);
    }

    if (scanner.hasMoreTokens()) {
        cout << "SYNTAX ERROR" << endl;
    }
}

void GOTO::execute(EvalState& state)
{
    // set the current line to line
    state.setCurrentLine(line);
}

IF::IF(TokenScanner& scanner)
{
    lhs = readE(scanner, 0);
    sign = scanner.nextToken(); // get the operator for comparison
    rhs = readE(scanner, 0);
    if (scanner.nextToken() != "THEN") {
        cout << "SYNTAX ERROR" << endl;
    }
    string temp = scanner.nextToken();
    line = stringToInteger(temp);
    if (scanner.hasMoreTokens()) {
        cout << "SYNTAX ERROR" << endl;
    }
}

IF::~IF()
{
    delete lhs;
    delete rhs;
}

void IF::execute(EvalState& state)
{
    int first = lhs -> eval(state);
    int second = rhs -> eval(state);

    if ((sign == "<" && first < second) || (sign == ">" && first > second) || (sign == "=" && first == second)) {
        state.setCurrentLine(line);
    }
}