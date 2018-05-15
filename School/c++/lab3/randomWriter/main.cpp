#include "randomWriter.h"

int main()
{
    // important global declarations
    int n;
    vector<string> wordList;
    map<string, vector<string>> wordMap;
    string answer;

    getPhrases(wordList);

    // get n
    cout << "Please insert N: ";
    cin >> n;
    cout << endl;
    // check if n is invalid. Reprompt if yes
    while (n < 2) {
        cout << "N cannot be 1 or negative!";
        cin >> n;
        cout << endl;
    }

    getMap(wordMap, wordList, n);
    answer = ngramGenerator(n, wordMap);
    print(answer);

    system("pause");
    return 0;
}