
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
        map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        int maxFreq = 0;
        for (auto p : freq)
        {
            maxFreq = max(maxFreq, p.second);
        }

        int ans;
        if (freq[1] == n)
        {
            ans = 0;
        }
        else if (maxFreq == freq[1])
        {

            ans = n - maxFreq;
        }
        else
        {
            ans = 1 + (n - maxFreq);
        }

        cout << ans << endl;
    }

    return 0;
}
