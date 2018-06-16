#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct transaction
{
    string give;
    string take;
    string amount;
    string time;

    bool operator < (const transaction& Tra) const
    {
        return (time < Tra.time);
    }
};

struct tree
{
    transaction Transaction;
    shared_ptr<tree> previous;
    vector<shared_ptr<tree>> next;
};

void chain(vector<transaction>& T, string& firstGive, shared_ptr<tree> current)
{
    if (current->Transaction.take == firstGive) {
        shared_ptr<tree> temp = current;
        cout << current->Transaction.take << " ";
        while (temp->previous != nullptr) {
            temp = temp->previous;
            cout << temp->Transaction.take << " ";
        }
        return;
    }

    for (int i = 0; i < T.size(); i++) {
        if (T[i].take == current->Transaction.give) {
            shared_ptr<tree> temp = make_shared<tree>();
            temp->Transaction = T[i];
            current->next.push_back(temp);
        }
    }

    for (int i = 0; i < current->next.size(); i++) {
        current->next[i]->previous = current;
    }

    int no = current->next.size();
    for (int i = 0; i < no; i++) {
        current = current->next[i];
        chain(T, firstGive, current);
    }

    // shared_ptr<tree> link = make_shared<tree>;
    // shared_ptr<tree> temp = link;

    // for (int i = 0; i < T.size(); i++) {
    //     firstGive = T[i];
    //     link -> Transaction = T[i];
    //     temp = link
    //     int k = i + 50; // changable
    //     for (int j = i; j < k; j++) {
    //         if (T[j].give == current->Transaction.take) {
    //             shared_ptr<tree> temp2 = make_shared<tree>;
    //             temp2 -> Transaction = T[j];
    //             temp -> next.push_back(temp2);

    //         }
    //     }
    // }
}

int main()
{
    string fileName = "temp.txt";
    vector<transaction> T;
    ifstream file;
    file.open(fileName);
    
    while (!file.eof()) {
        transaction temp;
        string rubbish, str1, str2;
        file >> temp.give;
        file >> rubbish;
        file >> temp.take;
        file >> rubbish;
        file >> temp.amount;
        file >> rubbish;
        file >> str1 >> str2;
        temp.time = str1+" "+str2;
        T.push_back(temp);
    }

    sort(T.begin(), T.end());
    
    cout << T[0].give << T[0].take << T[0].amount << T[0].time << endl;
    cout << T[1].give << endl;
    cout << T[0].take;

    shared_ptr<tree> current = make_shared<tree>();
    chain(T, T[0].give, current);

    file.close();

    system("pause");
    return 0;
}