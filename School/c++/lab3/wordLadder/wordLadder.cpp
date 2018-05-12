#include "wordLadder.h"

void getDictionary(set<string>& dictionary)
{
    // declarations
    string fileName, dictionaryToken;
    ifstream fileOpener;

    // doing initialisation
    cout << "please insert dictionary file name: ";
    cin >> fileName;
    cout << endl;
    fileOpener.open(fileName);

    // if file not opened, prompt again
    while (!fileOpener.is_open()) {
        cout << "file does not exist!" << endl;
        cout << "Please enter again: ";
        cin >> fileName;
        fileOpener.open(fileName);
        cout << endl;
    }

    // insert words into dictionary set
    while (fileOpener >> dictionaryToken) {
        dictionary.insert(dictionaryToken);
    }

    fileOpener.close();
}

void getWord(set<string>& dictionary, string& word1, string& word2)
{
    // requesting words
    cout << "insert word no1: ";
    cin >> word1;

    // check if dictionary has the word1. Reprompt is no
    while (dictionary.count(word1) != 1) {
        cout << endl << "word not found! Please re-enter: ";
        cin >> word1;
    }
    
    // check if dictionary has word2 and word1 has to be same length as word2. Reprompt if no
    cout << endl << "insert word no2: ";
    cin >> word2;
    while (dictionary.count(word2) != 1 && word1.length() != word2.length()) {
        cout << endl << "word not found or not same length! Please re-enter: ";
        cin >> word2;
    }
    cout << endl;
}

stack<string> ladderSolver(set<string>& dictionary, string& word1, string& word2)
{
    // declarations
    set<string> usedWords; // set of used words
    stack<string> temp; // stack acts as first stack in qs
    queue<stack<string>> qs; // stack in queue to store all possible ladder
    stack<string> current; // act as main stack in calculation later

    temp.push(word1);
    qs.push(temp);
    
    while (!qs.empty()) {
        
        current = qs.front(); // take the front queue of stack as current stack to perform algorithm
        qs.pop(); // remove the stack already taken by current
        string currentWord = current.top(); // start with the topmost string of current stack

        for (int i = 0; i < currentWord.length(); i++) {
            for (int j = 97; j < 123; j++) {
                
                string newWord = currentWord;
                newWord[i] = static_cast<char>(j); // convert ASCII to alphabet character
                
                if (dictionary.count(newWord) == 1 && usedWords.count(newWord) != 1) {
                    
                    if (newWord == word2) {
                        current.push(newWord);
                        queue<stack<string>> empty; // create empty queue of stack
                        swap(qs, empty); // if succesful, make original qs empty to prevent going through further loop
                        break;
                    } else {
                        usedWords.insert(newWord);
                        stack<string> newStack = current;
                        newStack.push(newWord);
                        qs.push(newStack); // create new branch of possible solution as queue of stack
                    }
                }
            }
        }
    }

    return current;
}

void print(stack<string> S) // no reference used. So original stack will not affected. Safe to pop()
{
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}