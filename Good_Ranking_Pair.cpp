#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    cout << 2 * n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i <<" " << i+1 <<" " << i+2 << endl;
    }
    return 0;
}