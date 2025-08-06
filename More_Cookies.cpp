#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c; // n -> the number of friends and c -> the number of Cookies Alice bought initially

        int e = c;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i]; // the i-th friend has Ci Cookies

        sort(a.begin(), a.end()); // All elements are sorted ascending order by this algorithm

        int mn = *(min_element(a.begin(), a.end())); // The minimum element has been taken from all elements

        int d = *(lower_bound(a.begin(), a.end(), c)); // vector<int> v = {1,3,5,5,7,9} and search for lower_bound(v.begin(),v.end(), 5), it will return an iterator pointing to the first 5(at index 2). If you search for lower_bound(v.begin(), v.end(), 4), it will return an iterator pointing to 5(at index 2) as 5 is the first element not less than 4
   

        if(c > mn && d != c)    // if(6>5 && 7 != 6)
        //4 6   
        //5 7 8 9
        //output -> 0
            cout << c - e << endl;

        else if(c > mn && d == c)
        {
            c += 1;
            while(*(lower_bound(a.begin(), a.end(), e == c)))
            {
                c++;
            }
            cout << c - e << endl;
        }
    }
    return 0;
}