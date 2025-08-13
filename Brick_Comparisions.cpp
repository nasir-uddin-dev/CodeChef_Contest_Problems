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

        int idx = 1;
        int sz = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > sz)
            {
                sz = a[i];
                idx = i+1;
            }
        }

        cout << idx << endl;
    }
    return 0;
}


