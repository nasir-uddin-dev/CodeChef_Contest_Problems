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
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int moves = 0;
        vector<int> diff;

        for (int i = 0; i < n; i++)
        {
            int cnt = min(abs(a[i] - b[i]), 9 - abs(a[i] - b[i]));
            int cnt2 = max(abs(a[i] - b[i]), 9 - abs(a[i] - b[i]));
            // cout << i << "->" << cnt << endl;
            moves += cnt;
             cout << i <<"-> "  << cnt2 << endl;
            diff.push_back(cnt2 - cnt);  //Odd
        }

        int minDiff = INT_MAX;

        for (int i = 0; i < diff.size(); i++)
        {
            minDiff = min(minDiff, diff[i]);  //Odd
        }

        //cout << minDiff << endl;

        // cout << moves << endl;
        int remain = k - moves;
        // cout << k <<" " << moves <<" " << remain << endl;

        // if (remain < 0)
        //     cout << "No" << endl;
        // else if (remain % 2 == 0 || minDiff <= remain)
        //     cout << "Yes" << endl;
        // else
        //     cout << "No" << endl;
    }
    return 0;
}