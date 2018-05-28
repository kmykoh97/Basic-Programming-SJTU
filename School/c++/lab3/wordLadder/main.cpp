#include "wordLadder.h"

int main()
{
    // global declaration
    string word1, word2; // first and last word of word ladder
    set<string> dictionary; // dictionary
    stack<string> answer; // final answer stored in stack

    getDictionary(dictionary);
    
    // loop and exit condition
    while (true) {
        getWord(dictionary, word1, word2);

        if (word1 == "N" || word2 == "N") {
            break;
        }

        answer = ladderSolver(dictionary, word1, word2);
        print(answer);
    }

    cout << "Have a nice day. ";

    system("pause");
    return 0;
}