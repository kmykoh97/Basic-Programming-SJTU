#include <iostream>

// return the sum of all elements in num[]
int findsum(int num[], int size)
{
    if (size == 0) {
        return num[size];
    }

    return num[size] + findsum(num, size-1);
}

int main()
{
    int numberArray[] = {0, 1, 2, 3}; // test case declaration

    std::cout << "Sum is: " << findsum(numberArray, sizeof(numberArray)/sizeof(int) - 1) << std::endl;

    system("pause");
    return 0;
}