/*
 * File: program.cpp
 * -----------------
 * This file is a stub implementation of the program.h interface
 * in which none of the methods do anything beyond returning a
 * value of the correct type.  Your job is to fill in the bodies
 * of each of these methods with an implementation that satisfies
 * the performance guarantees specified in the assignment.
 */

#include <string>
#include "program.h"
#include "statement.h"
using namespace std;

Program::Program() {
   first = new Line;
   last = new Line;

   first -> next = last;
   first -> previous = NULL;
   first -> content = "";
   first -> lineNumber = 0;
   first -> statement = NULL;
   last -> previous = first;
   last -> next = NULL;
   last -> content = "";
   last -> lineNumber = 0;
   last -> statement = NULL;
}

Program::~Program() {
   clear();
   delete first;
   delete last;
}

void Program::clear() {
   // declarations of 2 temporary pointer for easier deletion
   Line* temp;
   Line* tempFree;

   temp = first -> next;
   while (temp != last) {
       tempFree = temp;
       temp = temp -> next;
       delete tempFree -> statement; // free memory
       delete tempFree;
   }

   // reconnect first to last
   first -> next = last;
   last -> previous = first;
   lineMap.clear();
}

void Program::addSourceLine(int lineNumber, string line) {
   if (lineMap.containsKey(lineNumber)) { // if line with the number already exists
       Line* temp = lineMap.get(lineNumber); // points to the Line of this key
       temp -> content = line; // replace Line content
       delete temp -> statement;
       temp -> statement = NULL;
   } else { // line with the number does not exist
       Line* temp = new Line;
       temp -> content = line;
       temp -> lineNumber = lineNumber;
       temp -> statement = NULL;
       if (first -> next == last) { // linked list is empty
           temp -> next = last;
           temp -> previous = first;
           first -> next = temp;
           last -> previous = temp;
       } else { // linked list not empty
           Line* temp2 = first -> next;
           while (temp2 -> lineNumber < temp -> lineNumber && temp2 != last) {
               temp2 = temp2 -> next;
           }
           
           // do required pointing
           Line* temp3 = temp2 -> next;
           temp2 -> next = temp;
           temp -> previous = temp2;
           temp -> next = temp3;
           temp3 -> previous = temp;

           lineMap.add(lineNumber, temp);
       }
   }
}

void Program::removeSourceLine(int lineNumber) {
   if (lineMap.containsKey(lineNumber)) {
       Line* temp = lineMap.get(lineNumber);
       temp -> next -> previous = temp -> previous;
       temp -> previous -> next = temp -> next;
       delete temp -> statement;
       delete temp;
       lineMap.remove(lineNumber);
   }
}

string Program::getSourceLine(int lineNumber) {
   if (lineMap.containsKey(lineNumber)) {
       return lineMap.get(lineNumber) -> content;
   }

   return "";
}

void Program::setParsedStatement(int lineNumber, Statement *stmt) {
   if (lineMap.containsKey(lineNumber)) {
       Line* temp = lineMap.get(lineNumber);
       delete temp -> statement;
       temp -> statement = stmt;
   } else {
       error();
   }

Statement *Program::getParsedStatement(int lineNumber) {
   if (lineMap.containsKey(lineNumber)) {
       return lineMap.get(lineNumber) -> statement;
   }

   return NULL;
}

int Program::getFirstLineNumber() {
   if (first -> next != last) {
        return first -> next -> lineNumber;
    }
   
   return -1;
}

int Program::getNextLineNumber(int lineNumber) {
   if (lineMap.containsKey(lineNumber)) {
       Line* temp = lineMap.get(lineNumber);
       if (temp -> next != last) {
           return temp -> next -> lineNumber;
       }
   }
   
   return -1;
}
