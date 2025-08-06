#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int BhoomiHeight = a[n - 1]; // Bhoomi is the last student in the queue , with a height of H

        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= BhoomiHeight) // A student will be able to watch the performance if and only if they are strictly taller than every student ahead of them.
            {
                idx = i; // she can move to position i - 1
                break;
            }
        }

        cout << n - idx - 1 << endl;
    }
    return 0;
}