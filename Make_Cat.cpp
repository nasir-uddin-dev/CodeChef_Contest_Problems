
// Make Cat
// Chef loves cats, and tries to search for them everywhere.

// Today, Chef saw a string
// S
// S of length
// 3
// 3, consisting of lowercase English letters only.
// Your task is to tell Chef whether he can rearrange the letters of the string
// S
// S to form the word "cat".

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    // reverse(s.begin(), s.end());
    // auto it = s.find('cat');
    
 reverse(s.begin(), s.end());

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}