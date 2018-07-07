#include <iostream>

using namespace std;

void help()
{
    cout << "This is helping statement" << endl;
}

void databaseInput()
{
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            // findValue();
            break;
        case 2:
            help();
            break;
        default:
            cout << "wrong option chose!" << endl;
            break;
    }
}

void printPrompt()
{
    cout << "my > ";
}

// starting the database
void startDatabase()
{
    // system("clear");

    // introduction
    cout << "Welcome to my database" << endl;
    cout << "1. search" << endl;
    cout << "1. search" << endl;
    cout << "1. search" << endl;
    cout << "1. search" << endl;

    while (true) {
        printPrompt();
        databaseInput();
    }
}

int main()
{
    startDatabase();
    return 0;
}