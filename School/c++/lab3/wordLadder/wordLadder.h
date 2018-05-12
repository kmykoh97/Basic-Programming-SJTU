#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

// functions declarations
void getDictionary(set<string>& dictionary); // to get dictionary from a text file
void getWord(set<string>& dictionary, string& word1, string& word2); // to get 2 words from user
stack<string> ladderSolver(set<string>& dictionary, string& word1, string& word2); // to solve the ladder and return the stack
void print(stack<string> S); // to print the stack

#endif