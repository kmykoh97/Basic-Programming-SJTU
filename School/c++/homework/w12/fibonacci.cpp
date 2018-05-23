#include <iostream>

// return nth fibonacci number
int fibo(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    return fibo(n-2) + fibo(n-1);
}

// driver function
void fibonacci(int n)
{
    for (int i = 1; i <= n; i++) {
        std::cout << fibo(i) << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int n; // declaration

    std::cout << "Please insert fibonacci level: ";
    std::cin >> n;

    fibonacci(n);

    system("pause");
    return 0;
}