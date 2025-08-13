#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;

    int sum = a * b - min(a,b);
    cout << sum;
    return 0;
}