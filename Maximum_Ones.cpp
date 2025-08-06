//https://www.codechef.com/problems/MXON?tab=statement

//We just processed from the reverse order , ensured we have enough moves to perform any operation and then, as we are coming from the backwards, we need to check if our current element is '1' and current - 1 th element is '0' , if yes, we can update it as '1' and decrease our k count representing one operation has been performed... at last, just count the number of '1' s present in the string and print it

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int k1 = k;
        string s;
        cin >> s;
        for (int i = s.size() - 1; i > 0; i--) {
            if (k1 > 0) {
                if (s[i] == '1' && s[i - 1] == '0') {
                    s[i - 1] = '1';
                    k1--;
                }
            }
        }
        int cnt_1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') cnt_1++;
        }
        cout << cnt_1 << endl;
    }
}