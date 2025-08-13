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
        long long n;
        cin >> n;

        unordered_set<long long> visited;

        // Start from n, divide by 2 until odd
        while (true)
        {
            if (visited.insert(n).second)
            {
                // From this number, subtract 2 until <= 0
                long long x = n;
                while (x > 0)
                {
                    visited.insert(x);
                    x -= 2;
                }
            }
            if (n % 2 == 0)
                n /= 2;
            else
                break;
        }

        // Also handle the final odd number by subtracting 2
        long long x = n;
        while (x > 0)
        {
            visited.insert(x);
            x -= 2;
        }

        cout << visited.size() << "\n";
    }
    return 0;
}
