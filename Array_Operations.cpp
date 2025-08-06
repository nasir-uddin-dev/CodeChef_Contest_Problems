// https://www.codechef.com/problems/OPAR?tab=submissions
// To me, this was easier than the shall we play game problem.. All I did was to check if the maximum element of the array is in an even position or in an odd position. If it were in the even position, then I could use all possible operations on it, meaning I would add the total possible operation with the maximum element. As for odd index, I will add 1 less than the total possible operation. The total operation possible (n-1)/2; How? n-1, cause we will have one element at the end. As for why divide it by 2, you find it. If the max is on the even index then after every operation the max will be at even index and remember what the operation was(a[i]+1, a[i+1], a[i+2]+1) in here the left and right one is even index and every operation decreases the array size by two.

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (n == 1)
    {
        cout << v[0] << '\n';
        return;
    }
    int mx = *max_element(v.begin(), v.end());
    int pos = (n - 1) / 2;
    bool ans = false;
    for (int i = 0; i < n; i += 2)
    {
        if (v[i] == mx)
        {
            ans = true;
            break;
        }
    }
    int ex = ans ? pos : max(pos - 1, 0);
    cout << mx + ex << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
