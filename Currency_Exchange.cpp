// https://www.codechef.com/problems/CUREX

// Currency Exchange
//   Chef currently has A1 gold coins and B1 silver coins with him.
//   He can perform the following three types of transformations :
//   1)  Pay 1 gold coin and receive 5 silver coins.
//       This  can only be done if he has at least one gold coin
//   2)  Pay 5 silver coins and receive 1 gold coin.
//       This can only be done if he has at least five silver coins.
//   3)  Discard one gold coin and one silver coin
//       This can only be done if he has at least one gold coin and at least one silver coin.

//  Is it possible, using these transformation, for chef to end up with exactly A2 gold coins and B2 silver coins ?

/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;    // 2 1 2 1      //2 1 1 5

        bool pos = false;
        //Type -1
        for(int a = a1, b = b1; a >= 0; a--, b += 5)    // a = 2, b = 1; 2 >= 0; 1, 6   // a=2, b=1; 2>=0; 1,6
        {
            if(a2 <= a && b2 <= b && a - b == a2 - b2)  // if(2 <= 2 && 1 <= 1 && 2-1 == 2-1)   //if(1<=2 && 5 <= 1 && 2-1 == 1-5) This conditon is false
                pos = true;
        }

        //Type - 2
        for(int a = a1, b = b1; b >= 0; a++, b -= 5)    // a = 2, b = 1; 1 >= 0; 1, 6
        {
            if(a2 <= a && b2 <= b && a - b == a2 - b2)  //if(2 <= 2 && 1 <= 1 && 2-1 == 2-1)
                pos = true;
        }

        if(pos)
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
    }

    return 0;
} */

// The condition if(v1 >= v2 && (v1 - v2) % 6 == 0) checks whether it's possible to reach the target number of gold and silver coins using allowed operations. Here, v1 = 5a1 + b1 and v2 = 5a2 + b2 represent a combined "value" of coins, where 1 gold = 5 silver. Since all operations either preserve this total value or reduce it in multiples of 6 (like discarding one gold and one silver, which reduces value by 6), the difference between the starting and target values must be a non-negative multiple of 6. If both conditions are satisfied, it's possible to transform the starting state into the target state.

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;    //3 2 0 5
        int v1 = 5 * a1 + b1;   // v1 = 5 * (3+2) = 25
        int v2 = 5 * a2 + b2;   // v2 = 5 * (0+5) = 25
        if (v1 >= v2 && (v1 - v2) % 6 == 0) // if(25>=25 && (25 - 25) % 6 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}