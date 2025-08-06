// Solution
// Uniform Baking : Chef must choose a fixed number of X of cakes to bake each day
// Simulate Sales : For each possible X(from 0 to max customers), compute how many cakes he can sell each day (min(x, A[i]))
// Calculat profit : Total revenue : cakes sold * 50; Total cost : cakes baked * 30; Profit = revenue - cost
// Maximize profit : Try all X values and choose the one that gives the highest total profit
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

        int maxProfit = 0;
        for (int x = 1; x <= 100; x++)
        {
            int sold = 0;
            for (int i = 0; i < n; i++)
            {
                sold += min(x, a[i]) * 50;
                sold -= 30 * x;
            }

            maxProfit = max(maxProfit, sold);
        }

        cout << maxProfit << endl;
    }
    return 0;
}