// I have counted ones and twos, if no of ones are even then operations will be the minimum of ones and twos but if the no of ones are odd then we will convert all twos to the ones hence operations will be no of twos, We have done this because we want either all ones or all twos because if there are different no on the different index then 1+2 can never given even number. while in case of all ones or all twos, each pair of index will give even numbers on addition.

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int one = 0, two = 0;

    // tc-1 => 1 1 2 2
    //  ai + aj = 1+1 = 2 is even number
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        if (val == 1)
            one++; // two occurrence of one
        else
            two++; // two occurrence of two
    }

    // Option 1: Convert all 2s → 1s
    int ans = two;

    // Option 2: Convert all 1s → 2s (only possible if one is even)
    if (one % 2 == 0)            //(1+1) % 2 == 0
        ans = min(ans, one / 2); // ans = min(2,1)

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}