#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool ok = false;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (a[i] < 40 || sum == 100)
                ok = true;
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}