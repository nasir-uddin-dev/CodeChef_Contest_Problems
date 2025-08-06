// Problems Link : https://www.codechef.com/problems/FRMN
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        vector<long long> idx;
        for (int i = 0; i < n - 1; i++)
        {
            if (h[i - 1] > h[i] && h[i + 1] > h[i] || h[i - 1] < h[i] && h[i + 1] < h[i])
                idx.push_back(i);
        }

        long long ans = n * (n - 1) / 2;

        if (idx.size() < 2)
        {
            cout << ans << endl;
            continue;
        }

        long long prev = 0;
        for (int i = 0; i < idx.size() - 1; i++)
        {
            long long unfriend = (idx[i] - prev) * (n - 1 - idx[i + 1]);
            ans -= unfriend;
            prev = idx[i];
        }

        cout << ans << endl;
    }

    return 0;
}
