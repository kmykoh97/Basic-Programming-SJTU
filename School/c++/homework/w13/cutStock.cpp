#include <iostream>
#include <vector>

using namespace std;

// recursive wrapper function
int cutStock(vector<int>& requests, vector<int>& remains, int stockLength)
{
    // base case
    if (requests.size() == 0) {
        return 0;
    }

    int counter = stockLength; // initialise as maximum length

    // if there are still items in requests vector
    for (int i = 0; i < requests.size(); i++) {
        int temp = requests[i];
        int tempCounter = 0;

        // case of taking remaining rods
        for (int j = 0; j < remains.size(); j++) {
            if (remains[j] >= requests[i]) {
                int tempRemains = remains[j]; // hold value
                remains[j] -= requests[i];

                requests.erase(requests.begin()+i); // remove item
                tempCounter += cutStock(requests, remains, stockLength);

                // compare
                if (counter > tempCounter) {
                    counter = tempCounter;
                }

                remains[j] = tempRemains; // gives back value
                requests.insert(requests.begin()+i, temp); // reinsert item
                tempCounter = 0; // recallibrate to 0
            }    
        }

        // case of taking new rod: add remains -> add tempCounter -> remove requests -> recursive algorithm -> remove remains
        remains.push_back(stockLength-requests[i]);
        tempCounter++;
        requests.erase(requests.begin()+i);
        tempCounter += cutStock(requests, remains, stockLength);
        remains.pop_back();

        // compare
        if (counter > tempCounter) {
            counter = tempCounter;
        }

        // add request back to original position
        requests.insert(requests.begin()+i, temp);
    }

    return counter; // after compare, counter is the lowest possible value. Return
}

// driver function
int cutStock(vector<int>& requests, int stockLength)
{
    // if no request, returns 0
    if (requests.size() == 0) {
        return 0;
    }

    int counter = stockLength; // initialise as maximum length

    for (int i = 0; i < requests.size(); i++) {
        // declarations
        int temp = requests[i];
        int tempCounter = 0;
        vector<int> remains; // hold cut pipes

        // first time: add remains -> add tempCounter -> remove requests -> algorithm -> remove remains
        remains.push_back(stockLength-requests[i]);
        tempCounter++;
        requests.erase(requests.begin()+i);
        tempCounter += cutStock(requests, remains, stockLength);
        remains.pop_back();

        // compare
        if (counter > tempCounter) {
            counter = tempCounter;
        }

        // add requests back to original position
        requests.insert(requests.begin()+i, temp);
    }

    return counter;
}

int main()
{
    // declarations
    int stockLength;
    int noRequest;
    vector<int> requests;

    // takes necessary arguments
    cin >> stockLength >> noRequest;

    // fill the vector of requests
    for (int i = 0; i < noRequest; i++) {
        int temp;
        cin >> temp;
        requests.push_back(temp);
    }

    // print answer
    cout << "number of pipes needed: " << cutStock(requests, stockLength) << endl;

    system("pause");
    return 0;
}