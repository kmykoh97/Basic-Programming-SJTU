#include <iostream>
#include <cstring> // strlen()

// return true if palindrome
bool palindromeChecker(char a[], int start, int end)
{
    // if only 1 character available, return true
    if (start == end) {
        return true;
    }

    // if last character does not match first character, return false
    if (a[start] != a[end]) {
        return false;
    }

    // check characters inside the first and last characters recursively
    if (start < end) {
        return palindromeChecker(a, start+1, end-1);
    }

    return true;
}


// driver function to return 1 if a[] is a palindrome, 0 otherwise
int ispalindrome(char a[], int size)
{
    // empty string considered palindrome
    if (size == 0) {
        return 1;
    }

    // non-empty string, check palindrome status
    if (palindromeChecker(a, 0, size-1)) {
        return 1;
    }

    return 0;
}

int main()
{
    char test[] = "happqqppah"; // palindrome test case
    char test2[] = "notpalindrome"; // non-palindrome test case

    std::cout << ispalindrome(test, strlen(test)) << std::endl;
    std::cout << ispalindrome(test2, strlen(test2)) << std::endl;

    system("pause");
    return 0;
}