#include <iostream>

// return the minimum element in num[]
int findmin(int num[], int size)
{
    if (size == 0) {
        return num[0];
    }

    if (num[size] < findmin(num, size-1)) {
        return num[size];
    }

    return findmin(num, size-1);
}

int main()
{
    int numberArray[] = {1, 1, 2, 3, 0}; // test case declaration

    std::cout << "Minimum is: " << findmin(numberArray, sizeof(numberArray)/sizeof(int) - 1) << std::endl;

    system("pause");
    return 0;
}