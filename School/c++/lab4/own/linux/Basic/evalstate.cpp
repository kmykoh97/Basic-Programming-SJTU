/*
 * File: evalstate.cpp
 * -------------------
 * This file implements the EvalState class, which defines a symbol
 * table for keeping track of the value of identifiers.  The public
 * methods are simple enough that they need no individual documentation.
 */

#include <string>
#include "evalstate.h"

#include "../StanfordCPPLib/map.h"
using namespace std;

/* Implementation of the EvalState class */

EvalState::EvalState() {
   /* Empty */
}

EvalState::~EvalState() {
   /* Empty */
}

void EvalState::destroy()
{
    symbolTable.clear();
}

void EvalState::setValue(string var, int value) {
    if (var == "IF" || var == "REM" || var == "PRINT" || var == "LET" || var == "GOTO" || var == "END" || var == "INPUT") {
        cout << "SYNTAX ERROR" << endl;
        return;
    }
   symbolTable.put(var, value);
}

int EvalState::getValue(string var) {
    // if (!symbolTable.containsKey(var)) {
    //     cout << "VARIABLE NOT DEFINED" << endl;
    // }

   return symbolTable.get(var);
}

bool EvalState::isDefined(string var) {
   return symbolTable.containsKey(var);
}

void EvalState::setCurrentLine(int lineNumber)
{
    string temp = "currentLineNumber";
    return symbolTable.put(temp, lineNumber);
}

int EvalState::getCurrentLine()
{
    string temp = "currentLineNumber";
    return symbolTable.get(temp);
}