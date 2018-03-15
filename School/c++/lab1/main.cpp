#include "calculatorHeader.h"

int main()
{
    double answer = 0;
    while (cin) {
        token t = ts.get();
        if (t.kind == 'q') {
            break;
        } else if (t.kind == ';') {
            cout << answer << endl;
            break;
        } else {
            ts.putBack(t);
        }

        answer = expression();
    }

    system("pause"); // to view result

    return 0;
}