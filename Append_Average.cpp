// https://www.codechef.com/problems/AVGAPP?tab=statement
// 1 . Initial Sum Calculation: We calculate the sum of all elements. Sort the array to get the two smallest values: mn1 and mn2.

// 2.Insertion Logic: In each operation, we consider inserting the average of mn1 and mn2, i.e., avg = (mn1 + mn2 + 1) / 2 (we take the ceiling). If this average is strictly less than mn2, we insert it. We update the sum and also make mn2 = avg for the next iteration. But if the average is greater than or equal to mn2, further insertions will not improve the result. So we directly insert this average k times and break.

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int sum = accumulate(a.begin(), a.end(), 0LL);
    int m1 = a[0], m2 = a[1];
    while (k)
    {
        int avg = (m1 + m2 + 1) / 2;
        
        if (avg < m2)
        {
            sum += avg;
            m2 = avg;
            k--;
        }
        else
        {
            sum += avg * k;
            break;
        }
    }
    cout << sum << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}