// https://www.codechef.com/problems/OPAR?tab=submissions
// To me, this was easier than the shall we play game problem.. All I did was to check if the maximum element of the array is in an even position or in an odd position. If it were in the even position, then I could use all possible operations on it, meaning I would add the total possible operation with the maximum element. As for odd index, I will add 1 less than the total possible operation. The total operation possible (n-1)/2; How? n-1, cause we will have one element at the end. As for why divide it by 2, you find it. If the max is on the even index then after every operation the max will be at even index and remember what the operation was(a[i]+1, a[i+1], a[i+2]+1) in here the left and right one is even index and every operation decreases the array size by two.


// Explanation -2
//Solution Explanation
// So basically we need to get the maximum element and keep increasing its value by 1.
// How many times can we increase it?
// We can increase it by (n-1)/2 times because n is odd, and since the number of elements reduces by 2 every time, it would take (n-1)/2 operations to reduce the array to 1 element.

// Now ideally we want to increase the maximum element by 1 every time, but we can only do that if the maximum element is at A or C position in an (A, B, C) triplet.
// Now if the max element is at an odd position or an even position, it will stay there since the parity does not change after the operation, no matter which of the three positions our element is in.
// We can increase the element by 1 no matter if it is at an even or odd position, until there are at least 4 elements in the array.
// Because among 4 elements, we can always find a triplet such that the max element is at an even position.

// But things change when we have only 3 elements left in the array.
// In that case, we can only increase the max element by 1 if it is at an even position.

// So we need to check if the max element is at an even position or not.
// If the element is at an even position, then we can increase it by 1 every time.
// If the element is at an odd position, then we can only increase it by 1, one less time than what we could have if it was at an even position.
// So that’s the solution.
// One last thing:
// We need to check if there are multiple max elements in the array.

// If even one of them is at an even position, then we can increase the max element by 1 every time.
// If all of them are at odd positions, then we can only increase it by 1, one less time than what we could have if it was at an even position.


#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7; // for (10^9)+7.

void take_input(vector<int>& vec, int n) {
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
}

int solve(vector<int>& vec,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,vec.at(i));
    }
    vector<int>max_ele_pos;
    
    bool is_at_least_one_max_pos_at_even_pos=false;
    
    for(int i=0;i<n;i++){
        if(vec.at(i)==maxi) {
            max_ele_pos.push_back(i);
            if(i%2==0){
                is_at_least_one_max_pos_at_even_pos = true;
                break;
            }
        }
        
    }
    return is_at_least_one_max_pos_at_even_pos ? maxi+((n-1)/2) : maxi+((n-1)/2)-1;
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> vec;
        take_input(vec, n);
        cout<<solve(vec,n)<<endl;
    }
}