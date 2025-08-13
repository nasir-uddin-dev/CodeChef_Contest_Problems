//https://www.codechef.com/problems/GOODRANK2?tab=ide
//if we want to achieve the condition of for each pair(a,b) , a beats b and b beats a , the first thing i noticed is that for n == 250 etc ... i cant generate the test like answer in under 10 lines ... so i just noticed for example : for n = 4 v = 1 , 2 , 3 , 4 | this will always be my first line , lets pick a random number , [2] , in that line 2 beats everyone in front of it , the same for [3] ans [1] , but [4] beats no one , so why not just reverse the array and see , voila ...
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a = 1;
    int k = n;
    cout << 2 << endl;
    while (n--)
    {
        cout << a << " ";
        a++;
    }
    cout << endl;
    --a;
    while (k--)
    {
        cout << a << " ";
        a--;
    }
    cout << endl;
}