#include "randomWriter.h"

void getPhrases(vector<string>& wordList)
{
    // declarations
    ifstream fileOpener;
    string fileName;
    string wordToken;

    // open file
    cout << "Please insert file name: ";
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

    // get all the words and store in a vector container
    while (fileOpener >> wordToken) {
        wordList.push_back(wordToken);
    }

    fileOpener.close();
}

void getMap(map<string, vector<string>>& wordMap, vector<string>& wordList, int n)
{
    // declarations
    queue<string> Queue; // uses queue container for easier removal of previous word and adding new word

    // push first n - 1 words into queue
    for (int i = 0; i < n-1; i++) {
        Queue.push(wordList[i]);
    }

    for (int j = n-1; j < wordList.size()+(n-1); j++) {
        int i = (j + wordList.size()) % wordList.size(); // solve overbound problem
        string currentWord = combineQueue(Queue);

        // if currentWord already exists as key in map:
        if (wordMap.count(currentWord) == 1) {
            wordMap[currentWord].push_back(wordList[i]);
        } else { // not exist, create new key-value
            vector<string> temp = {wordList[i]};
            wordMap[currentWord] = temp;
        }

        // delete first queue and add new word in line then repeat the process
        Queue.pop();
        Queue.push(wordList[i]);
    }
}

string ngramGenerator(int n, map<string, vector<string>>& wordMap)
{
    // declarations
    int wordNumber; // number of words displayed requested
    int currentWordNumber = 0; // to take count of current number of words
    stringstream ss; // to temporary store key to place in Queue
    string currentKey; // store random key
    vector<string> currentValue; // store value pair based on key
    queue<string> Queue; // for easier control of string in and out
    string answer = ""; // to store answer string

    cout << "Insert number of words to generate: ";
    cin >> wordNumber;
    // check if wordNumber is invalid
    while (wordNumber < n) {
        cout << "Number of words to display are too less!"
        cin >> wordNumber;
        cout << endl;
    }

    // get random key and value pair from map
    auto item = wordMap.begin();
    advance(item, rand()%wordMap.size());
    currentKey = item -> first;
    currentValue = item -> second;

    // push 2 words from key of wordMap into Queue
    ss << currentKey;
    for (int i = 0; i < 2; i++) {
        string temp;
        ss >> temp;
        Queue.push(temp);
    }

    // alters Queue and takes new key-value from wordMap on every loop
    while (currentWordNumber < wordNumber) {
        string temp = currentValue[rand()%currentValue.size()];
        answer += temp + " ";
        Queue.pop();
        Queue.push(temp);

        currentKey = combineQueue(Queue);
        currentValue = wordMap[currentKey];

        currentWordNumber++;
    }

    return answer;
}

string combineQueue(queue<string> Queue) // safe to pop() as no reference directed
{
    string combineString = "";

    while (!Queue.empty()) {
        combineString += Queue.front() + " ";
        Queue.pop();
    }

    return combineString;
}

void print(string answer)
{
    cout << "..." << answer << "..." << endl;
}