#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> pre(n);

        pre[0] = a[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + a[i];

        // bool ok = false;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += pre[i];
        }

        if (sum % 2 == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        // if (ok)
        //     cout << "Yes" << endl;
        // else
        //     cout << "No" << endl;
    }
}