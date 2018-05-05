#include "pqueue.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

int main()
{
    try {    
        PriorityQueue<int> pq; // declaration of priority queue
        ifstream fileOpener; // declaration of fstream to open or read file
        string fileName; // declaration of string to store file name
        string storage; // declaration of string to store lines in text files
        string tempstring = ""; // declaration of string to store values got in text files
        vector <int> v1; // declaration of vector container to store 2 values got from text file to enqueue() method

        cin >> fileName; // get the file name
        fileOpener.open(fileName); // open the file to read

        for (int i = 0; !fileOpener.eof(); i++) { // get lines from text file and store the whole line in storage as a string
            getline(fileOpener, storage);
            bool flag = false;

            for (string::size_type j = 0; j < storage.size(); j++) {
                if (flag) {
                    flag = false;
                    continue;
                }

                // check size of vector to see if enqueue() need to be called
                if (v1.size() == 2 && !isdigit(storage[j+1])) {
                    pq.enqueue(v1[0], v1[1]);
                    v1.clear();
                }

                // check if there is -1 to call dequeue() method or just treat as regular negative integer
                if (storage[j] == '-') {
                    if (storage[j+1] == '1') {
                        cout << pq.dequeue() << " ";
                        flag = true; // to prevent double interpretation of '1'
                        continue;
                    } else {
                        tempstring += storage[j]; // append to a string
                        continue;
                    }
                }

                // check if the character is a digit
                if (isdigit(storage[j])) {
                    tempstring += storage[j]; // append characters of integer to a string
                    if (!isdigit(storage[j+1])) { // check if there is any digit left after this digit
                        v1.push_back(stoi(tempstring)); // convert string to integer and store in vector
                        tempstring = ""; // reinitiate as empty string
                    }
                }

                // skips if useless characters found
                if (storage[j] == '(' || storage[j] == ')' || storage[j] == ',' || storage[j] == ' ') {
                    continue;
                }
            }
        }


        fileOpener.close(); // close file

        system("pause");
        return 0; // exit as success
    }

    catch(badInput) {
        cout << "error" << endl;
        system("pause"); // prevent screen blinking
        return 1; // exit as failure
    }
}