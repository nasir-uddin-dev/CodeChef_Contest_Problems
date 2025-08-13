// https://www.codechef.com/problems/RESREM

// Your are given two binary arrays A and B, of length N and M respectively.
// You can perform the following operation :
//   1)  Choose an index i (1<=i<=min(|A|,M)) such that A[i] = B[i].
//       Here |A| denotes the current length of A.
//   2) Delete A[i] from A. This reduces the length of A by 1.
//   3) Then , re-index the remaining elements of A to start from 1, without charging their order.

// For example , suppose A = [0,0,0,1] and B = [1,0]
// Choosing i = 2 (valid because A[2] = B[2] = 0) allows us to delete A[2] 0 from A. After this, A = [0,0,1].
// Since the elements were re-indexed, we can once again choose i = 2 to delete A[2], obtaining A = [0,1]. No more operations can be performed.

// Find the minimum possible final length of A, if you perform operations optimally.

//  A = [0,0,1,1,1,0,1,0,1,1,0,1,1,0]
//  B = [1,1,0,1,0]
// When two elements are aligned in array A and B, we can pop the elements in array A.
// Some orders of poping are better than others.
// Poping a later element VS an earlier element is always better (greedy)

// A = [0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1]
// B = [1,0,1,1,1,0,0,0]
// array A and B , index is 2 , two elements are aligned, possible option 1
// array A and B, index is 5, two elements are aligned , possible option 2
// From array A index 5 to last index, going to be shifted anyways
// From array A index 2 to 5, only be shifted if 1 is popped

// Pop the last position i where a[i] == b[i]
// First, do this repeatedly until we can't. print the size of A.

// Expected Time Complexity  : 0(N)
// Approach : greedily do the last alignment fist, later the earlier alignments

// How to do this in 0(n) or 0(nlogn) ?
// For a given a[i] to be popped
//   -> if (a[i] == 1) -> we need to find the earliest previous b[j] = 1.
//   -> if (a[i] == 0) -> we need to find the earliest previous b[j] = 0
//  how much "distance" to the previous  equal value

// Algorithm :
//  For each value i, (i <= n)
//   find the previous position j such that b[j] == a[i]
//  Prefix array approach
// For each value i,
// distance = i - prev[i]
// if(deletion >= distance){
//  we can reach and make a new deletion. we can just
// deletion ++;
//}
// ans = N - deletion

// some brief idea of an alternate approach
//  a = [0,.........]       a = [1,.........]
//  b = [0,1]               b = [1,0,.......]
// after this pattern -> entire of array A can be deleted

/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> b(m);
        for (auto &x : b)
            cin >> x;

        vector<int> prev_0(n, 1e9), prev_1(m, 1e9);
        for (int i = 0; i < n; i++)
        {
            if (i)
                prev_0[i] = prev_0[i - 1] + 1;
            if (i)
                prev_1[i] = prev_1[i - 1] + 1;
            if (i < m && b[i] == 0)
                prev_0[i] = 0;
            if (i < m && b[i] == 1)
                prev_1[i] = 0;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0 && prev_0[i] <= ans)
                ans++;
            if (a[i] == 1 && prev_1[i] <= ans)
                ans++;
        }

        cout << n - ans << endl;
    }

    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<vector<int>> nx(2, vector<int>(n + 1, 1e9));
    nx[b[0]][0] = 0;
    for (int i = 1; i < m; i++)
    {
        nx[0][i] = nx[0][i - 1] + 1;
        nx[1][i] = nx[1][i - 1] + 1;

        if (b[i] == 0)
        {
            nx[0][i] = 0;
        }
        else
        {
            nx[1][i] = 0;
        }
    }

    for (int i = m; i < n; i++)
    {
        nx[0][i] = nx[0][i - 1] + 1;
        nx[1][i] = nx[1][i - 1] + 1;
    }

    vector<int> req(n + 1);
    vector<int> cnt(n + 1);

    for (int i = n - 1; i >= 0; i--)
    {

        int r = nx[a[i]][i];
        if (r == 0)
        {
            cnt[i + 1]++;
        }
        else
        {
            req[i] = r;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cnt[i] >= req[i] && (i >= m || a[i] != b[i]))
        {
            cnt[i + 1]++;
        }
        cnt[i + 1] += cnt[i];
    }
    cout << n - cnt[n] << endl;
}

int32_t main()
{
    init_code();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

Initialization
    INF = 1000000000 prev_0 = [ INF, INF, INF ] prev_1 = [ INF, INF, INF ]

    Loop i = 0 :

    i == 0 so we skip i - dependent increment.i < m and
             b[0] == 0 → set prev_0[0] = 0. b[0] is not 1 so prev_1[0] remains INF.Now : prev_0 = [ 0, INF, INF ],
    prev_1 = [ INF, INF, INF ].

             Loop i = 1 : prev_0[1] = prev_0[0] + 1 = 0 + 1 = 1. prev_1[1] = prev_1[0] + 1 = INF + 1 = INF + 1(still effectively INF).i < m and b[1] == 1 → set prev_1[1] = 0. Now : prev_0 = [ 0, 1, INF ],
    prev_1 = [ INF, 0, INF ].

             Loop i = 2 : prev_0[2] = prev_0[1] + 1 = 1 + 1 = 2. prev_1[2] = prev_1[1] + 1 = 0 + 1 = 1. i < m and b[2] == 0 → set prev_0[2] = 0. Now : prev_0 = [ 0, 1, 0 ],
    prev_1 = [ INF, 0, 1 ].

             Second pass : ans = 0

    i = 0 : a[0] == 0 and prev_0[0] == 0 → 0 <= 0 true → ans = 1 i = 1 : a[1] == 1 and prev_1[1] == 0 → 0 <= 1 true → ans = 2 i = 2 : a[2] == 1 and prev_1[2] == 1 → 1 <= 2 true → ans = 3

                                                                                                                                                                                         Result printed : n -
                                                                                                                                                                                                          ans = 3 - 3 = 0.

                                                                                                                                                                                                                        So in this example every element of a got matched → zero left unmatched.
