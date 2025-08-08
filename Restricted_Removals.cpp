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
//From array A index 2 to 5, only be shifted if 1 is popped

//Pop the last position i where a[i] == b[i]
//First, do this repeatedly until we can't. print the size of A.

//Expected Time Complexity  : 0(N)
//Approach : greedily do the last alignment fist, later the earlier alignments

//How to do this in 0(n) or 0(nlogn) ?
//For a given a[i] to be popped
//  -> if (a[i] == 1) -> we need to find the earliest previous b[i] = 1.
//  -> 