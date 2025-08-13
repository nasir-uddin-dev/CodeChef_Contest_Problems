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
        int totalXor = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            totalXor ^= a[i];
        }

        int finalScore = INT_MAX;

        for (int jB = 0; jB < n; jB++)
        { // Bob chooses
            int currentMax = INT_MIN;
            for (int jA = 0; jA < n; jA++)
            { // Alice chooses
                int score = totalXor ^ a[jA] ^ a[jB];
                currentMax = max(currentMax, score);
            }
            finalScore = min(finalScore, currentMax);
        }

        cout << finalScore << "\n";
    }

    return 0;
}