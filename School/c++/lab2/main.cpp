/* Calculator by Meng Yit Koh
517030990022
Shanghai Jiao Tong University */

// #include "header.h"
#include "gui.h"

double ANS = 0; // to store ANS

int main()
{
    gui* calculatorWindow = new gui();
    calculatorWindow -> show();

    system("pause"); // to show result
    // return 0; // indicating success
}
