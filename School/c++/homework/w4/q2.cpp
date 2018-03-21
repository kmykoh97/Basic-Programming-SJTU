#include <iostream>
#include <vector>

using namespace std;

int magicalString(int n) {
    // declarations
    vector <int> v1(n, 0);
    int ans, previousNumbering,currentNumbering, noNumber, vectorIndex;
    
    // values init
    ans = 0;
    previousNumbering = 1;
    currentNumbering = 1;
    noNumber = 0;
    vectorIndex = 0;

    while (noNumber < n-1) {
        v1[noNumber] = currentNumbering;
        ans = (currentNumbering == 1) ? (ans + 1) : (ans);
        vectorIndex++;
        
        if (previousNumbering == 2) {
            noNumber++;
            v1[noNumber] = currentNumbering;
            ans = (currentNumbering == 1) ? (ans + 1) : (ans);
            vectorIndex++;
        }
        
        currentNumbering = 3 - currentNumbering;
        previousNumbering = v1[vectorIndex];
        noNumber++;
    }

    return ans;
}

int main()
{
    int n, ans;
    cin >> n;
    ans = magicalString(n);
    cout << ans << endl;

    system("pause");
    return 0;
}