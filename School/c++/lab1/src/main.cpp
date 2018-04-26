/* Calculator by Meng Yit Koh
517030990022
Shanghai Jiao Tong University */

#include "header.h"

double ANS = 0; // to store ANS

int main()
{
    // cout << "This is a command line calculator to do +-*/%!" << endl;

    try {
        calculate(); // do main calculation
    }

    // catch all errors returned by function error()
    catch (badToken) {
        ts.restart(); // clear unwanted memories
        main(); // restart when error catched
    }

    catch (...) {
        exit(1); // indicating failure
    }

    system("pause"); // to show result
    // return 0; // indicating success
}