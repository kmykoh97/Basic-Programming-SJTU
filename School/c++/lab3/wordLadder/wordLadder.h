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
void getDictionary(set<string>& dictionary);
void getWord(set<string>& dictionary, string& word1, string& word2);
stack<string> ladderSolver(set<string>& dictionary, string& word1, string& word2);
void print(stack<string> S);

#endif