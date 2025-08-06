//https://www.codechef.com/problems/SWPG?tab=statement

//explained in comments, just do as the questions says, as Alice wants to minimize X - Y therefore at any point of time se wont let the negative value more decreased and so she will add to it, and similarly, she wont let the positive value to get increased more, so she will subtract to it, so that the value of X and Y can be minimized and hence X - Y which is essentially the sum of abs(X) + abs(Y), because y will be always negative or zero, can be minimzed.

// and similarly BOB will try to do the opposite to maximize X - Y, he will subtract to the negative value to decrease it further and  add to the positive value to increase it further..

// Now if n = odd, then ans = X - Y = 2^(n-1), (two raised to the power n-1), and if n = even, then ans = X - Y = 3*2^(n-2), (three times two raised to the power n-2)

// how these formulaes came are explained in the comments from line 8 to 31.

// Upvote if you liked the explanation.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;

// just simulate this for n = 9 (odd) and n = 10 (even), you will get the proof

// for n = 9
// 1    2    3    4    5    6    7    8    9
// A    B    A    B    A    B    A    B    A
// 1    3   -1   -9    7    39  -25  -153  103

// so for n = 9 (odd) the max score reached is at last and min score reached at second
// last and -153 + 2^8 (2^n-1) = 103 this implies 103 + 153 = 2^8 i.e. 103 - (-153) = 2^8
// i.e. x-y = 2^(n-1);



// for n = 10
// 1    2    3    4    5    6    7    8    9    10
// A    B    A    B    A    B    A    B    A     B
// 1    3   -1   -9    7    39  -25  -153  103  615

// so for n = 10 (even) the max score reached is at last and min score reached at third
// last and x - y = 615 - (-153) = (103 + 2^9) + 153 = 2^9 + (103 + 153), and (103 + 153)
// is 2^8 from above, so x - y = 2^9 + 2^8 = 2*2^8 + 2^8 = 3*2^8 i.e. x - y = 3*2^(n-2).


// used the modPow to get result of pow function in moded form.



long long mod_pow(long long base, int exp, int mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        int ex = n - 1;
        ll ans = mod_pow(2, ex, mod);
        cout << ans << endl;
    } 
    
    else {
        int ex = n - 2;
        ll pow_two = mod_pow(2, ex, mod);
        ll ans = (3 * pow_two) % mod;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}