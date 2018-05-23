#include <iostream>

// return the sum: 1 + 2 + 3 + ..... + n
int sum(int n)
{
    if (n == 1) {
        return 1;
    }

    return n + sum(n-1);
}

int main()
{
    int n; // declaration

    std::cout << "Please insert number of sum: ";
    std::cin >> n;

    std::cout << sum(n) << std::endl;

    system("pause");
    return 0;
}