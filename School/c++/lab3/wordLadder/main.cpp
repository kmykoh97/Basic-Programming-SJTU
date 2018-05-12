#include "wordLadder.h"

int main()
{
    // global declaration
    string word1, word2; // first and last word of word ladder
    set<string> dictionary; // dictionary
    stack<string> answer; // final answer stored in stack

    getDictionary(dictionary);
    getWord(dictionary, word1, word2);
    answer = ladderSolver(dictionary, word1, word2);
    print(answer);

    system("pause");
    return 0;
}