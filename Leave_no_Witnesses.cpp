//https://www.codechef.com/problems/DISPART

//  Leave no Withnesses (কোন সাক্ষীকে রাখবেন না)
//Let B be a binary string of length N.
//The integer X is said to be a withness for B if the following condition holds :
//  Consider two arrays S1 and S2, initially both empty.
//  For each index i (1 <= i <= N)
//      if B[i] = 0, append (X & i) to S1.
//      Here, & represents the bitwise AND operation.
//      if B[i] = 1, append (X | i) to S2.
//      Here | represents the bitwise OR operation.
//In the end, if S1 common S2 = empty holds, S1 and S2 have no common elements, then X is said to be a withness for B.

//For example , consider B = 010
//  X = 1 is a witness for this string , because S1 = [1 & 1, 1 & 3] = [1, 1], and S2 = [1 | 2] = [3] are disjoint.
//  X = 2 is not a witness for this string, because S1 = [2 & 1, 2 & 3] = [0,2] and S2 = [2|2] =[2] are not disjoint (they both contain the element 2)


//You are given a binary string A of length N.
//In one operation, you can choose an index i(1<=i<=N), and flip the character at index i. convert it from 0 to 1 or vice versa.

//Find the minimum number of operations needed to convert A into a binary string such that no longer from 1  to N is a witness to it.
//Note that we do not care whether integers larger than N are witness or not - just that no longer between 1 and N is a witness.
//If it's impossible to convert A to such a binary string no matter what, print -1 instead.

