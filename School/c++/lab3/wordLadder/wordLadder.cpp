#include "wordLadder.h"

void getDictionary(set<string>& dictionary)
{
    // declarations
    string fileName, dictionaryToken;
    ifstream fileOpener;

    // doing initialisation
    cout << "Dictionary file name? ";
    cin >> fileName;
    fileOpener.open(fileName);

    // if file not opened, prompt again
    while (!fileOpener.is_open()) {
        cout << "Unable to open that file. Try again. " << endl;
        cout << "Dictionary file name? ";
        cin >> fileName;
        fileOpener.open(fileName);
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
    cout << endl << "Word #1 (or N to quit): ";
    cin >> word1;
    cout << "Word #2 (or N to quit): ";
    cin >> word2;

    // check several conditions. Reprompt if not met
    while (dictionary.count(word1) != 1 || dictionary.count(word2) != 1 || word1 == word2 || word1.size() != word2.size()) {
        if (word1 == "N" || word2 == "N") {
            break;
        }
        
        cout << "The two words must be found in the dictionary, different and have same length. " << endl;
        cout << endl << "Word #1 (or N to quit): ";
        cin >> word1;
        cout << "Word #2 (or N to quit): ";
        cin >> word2;
    }
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
    
    cout << endl;
}