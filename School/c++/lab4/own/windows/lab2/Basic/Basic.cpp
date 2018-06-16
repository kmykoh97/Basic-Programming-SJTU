/*
 * File: Basic.cpp
 * ---------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the BASIC interpreter from
 * Assignment #6.
 * [TODO: extend and correct the documentation]
 */

#include <cctype>
#include <iostream>
#include <string>
#include "exp.h"
#include "parser.h"
#include "program.h"
#include "statement.h"
#include "../StanfordCPPLib/error.h"
#include "../StanfordCPPLib/tokenscanner.h"
#include "../StanfordCPPLib/simpio.h"
#include "../StanfordCPPLib/strlib.h"
using namespace std;

/* Function prototypes */

void processLine(string line, Program & program, EvalState & state);

/* Main program */

int main() {
   EvalState state;
   Program program;
//    cout << "Stub implementation of BASIC" << endl;
   while (true) {
      try {
         processLine(getLine(), program, state);
      } catch (ErrorException & ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
   }
   return 0;
}

/*
 * Function: processLine
 * Usage: processLine(line, program, state);
 * -----------------------------------------
 * Processes a single line entered by the user.  In this version,
 * the implementation does exactly what the interpreter program
 * does in Chapter 19: read a line, parse it as an expression,
 * and then print the result.  In your implementation, you will
 * need to replace this method with one that can respond correctly
 * when the user enters a program line (which begins with a number)
 * or one of the BASIC commands, such as LIST or RUN.
 */

void processLine(string line, Program & program, EvalState & state) {
   TokenScanner scanner;
   int lineNumber;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   scanner.setInput(line);
   string token = scanner.nextToken();
   TokenType tokenType = scanner.getTokenType(token);
   
   if (tokenType == NUMBER) {
       if (scanner.hasMoreTokens()) {
           string token2 = scanner.nextToken();

           if (token2 == "IF" || token2 == "REM" || token2 == "PRINT" || token2 == "LET" || token2 == "GOTO" || token2 == "END" || token2 == "INPUT") {
                string tempLine;
                scanner.saveToken(token2);
                scanner.saveToken(token);
                while (scanner.hasMoreTokens()) {
                    tempLine += scanner.nextToken() + " ";
                }
                tempLine.pop_back();
                scanner.setInput(line);
                token = scanner.nextToken();
                program.addSourceLine(stringToInteger(token), tempLine);
                Statement* statement = parseStatement(scanner);
                program.setParsedStatement(stringToInteger(token), statement);
            } else {
                cout << "SYNTAX ERROR" << endl;
                return;
            }

       } else {
           program.removeSourceLine(stringToInteger(token));
       }
   }

   if (tokenType == WORD) {
       if (token == "IF" || token == "REM" || token == "PRINT" || token == "LET" || token == "GOTO" || token == "END" || token == "INPUT") {
            // do required execution of Statement keywords
            scanner.saveToken(token);
            Statement* statement = parseStatement(scanner);
            statement -> execute(state);
            delete statement;
       } else if (token == "LIST") {
           lineNumber = program.getFirstLineNumber();
           while (lineNumber != -1) {
               cout << program.getSourceLine(lineNumber) << endl;
               lineNumber = program.getNextLineNumber(lineNumber);
           }
       } else if (token == "RUN") {
           state.setCurrentLine(program.getFirstLineNumber());
           lineNumber = state.getCurrentLine();
           while (lineNumber != -1) {
               if (program.hasLineNumber(lineNumber) == false) {
                   cout << "LINE NUMBER ERROR" << endl;
                   return;
               }

               Statement* statement = program.getParsedStatement(lineNumber);
               state.setCurrentLine(program.getNextLineNumber(lineNumber));
               statement->execute(state);
               lineNumber = state.getCurrentLine();
           }
       } else if (token == "HELP") {
            cout << "help" << endl;
       } else if (token == "CLEAR") {
           program.clear();
           state.destroy();
       } else if (token == "QUIT") {
           exit(0);
       } else {
           cout << "invalid command!" << endl;
       }
   }
}