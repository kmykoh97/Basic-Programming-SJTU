#ifndef RANDOMWRITER_H
#define RANDOMWRITER_H

#include <random>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

// functions declarations
void getPhrases(vector<string>& wordList); // store words in input file in wordList vector
void getMap(map<string, vector<string>>& wordMap, vector<string>& wordList, int n); // to get a map of key-value pairs
string ngramGenerator(int n, map<string, vector<string>>& wordMap); // to generate random sentences based on map generated
string combineQueue(queue<string> Queue); // to combine strings in queue into one string
void print(string answer); // to output answer;

#endif