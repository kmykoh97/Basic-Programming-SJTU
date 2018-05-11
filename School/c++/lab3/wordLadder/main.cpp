#include "wordLadder.h"



int main()
{
    string word1, word2;
    set<string> dictionary;
    stack<string> answer;
    getDictionary(dictionary);
    getWord(dictionary, word1, word2);
    answer = ladderSolver(dictionary, word1, word2);
    print(answer);

    system("pause");
    return 0;
}