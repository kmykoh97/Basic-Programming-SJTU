#include <iostream>
#include <string>
// #include <cstring> // strcmp()

using namespace std;

struct InputBuffer
{
    string buffer;
    int length;
}

InputBuffer* newInputBuffer()
{
    InputBuffer* inputBuffer = malloc(sizeof(InputBuffer));
    inputBuffer -> buffer = "";
    inputBuffer -> length = 0;

    return inputBuffer;
}

void printPrompt()
{
    cout << "test > ";
}

int main()
{
    InputBuffer* inputBuffer = newInputBuffer();

    while (true) {
        printPrompt();
        readInput();

        if (strcmp(inputBuffer -> buffer, ".exit") == 0) {
            exit(SUCCESS);
        } else {
            cout << "unrecognized commands!" << endl;
        }
    }
}