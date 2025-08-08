// https://www.codechef.com/problems/MINMAXMEX

// Minimize Maximum Mex
//   The MEX of an array of integers is defined to be the smallest non-negative integer not present in it.

//  For example, MEX([2,3,1,2]) = 0 and MEX([2,0,3]) = 1.

//  You are given two arrays A and B, both of length N.
//  You can perform the following operation on the arrays :
//  1) Choose an index i(1<=i<=N), and swap A[i] and B[i];

//  Find the minimum possible value of max(MEX(A), MEX(B)) if you are allowed to perform as many operations as you like (possibly, none).

// What the problem wants
// We have two arrays A and B of the same length
// We can swap the element at the same index (A[i] <-> B[i]) as many times as we want

// Our goal is to make : min (max(MEX(A), MEX(B)))
// That means :
//   1) We compute MEX(A) and MEX(B)
//   2) We take the maximum of those two values.
//   3) We want to make that maximum as small as possible.

// Reminder : What is MEX ?
//   MEX of an array = smallest non-negative integer not present in the array.
// Examples :
//          MEX([2,3,1,2]) -> 0(because 0 is missing)
//          MEX([2,0,3]) -> 1 (because 0 is present, but 1 is missing)

// Important observation
// If we want max(MEX(A),MEX(B)) to be small,
// it means both arrays must have all numbers from 0 up to some k-1.
//   Example :
//           if max(MEX) <= 2
//               -> both arrays must have 0 and 1 inside them (maybe in any order).

// Why swapping matters
// We can only swap at the same index, so :
//   If A[i] has 0 and B[i] has 1, we can swap to send 0 to the array that needs it.
//   But if both A[i] and B[i] lack a certain number, we can't magically create it
// So, the key observation is :
//   The smallest possible k (max MEX) is the smallest integer x such that for some number x , there exists at least one index where both A[i] and B[i] are equal to x.

// Because :
//          If at some number x, we have both copies in the same index, one of the arrays will miss it no matter what we swap.
//           That missing number becomes the MEX of at least one array, so max(MEX) >= x + 1

// A=[0,1,2]
// B=[1,0,2]
// All numbers 0,1,2 are spread out - no index has the same value in both arrays.
//We can rearrange by swapping to make :
//A=[0,1,2]
//B=[0,1,2]
//MEX(A) = 3, MEX(B) = 3 -> max = 3