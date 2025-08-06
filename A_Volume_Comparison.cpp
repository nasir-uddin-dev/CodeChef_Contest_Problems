#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int volume = a * b * c;

    int val = pow(x, 3);

 
    if (volume == val)
        cout << "Equal" << endl;
    else if (volume > val)
        cout << "Cuboid" << endl;
    else
        cout << "Cube" << endl;

    return 0;
}