//https://www.codechef.com/problems/GAMEEZ
// Problem Restatement & Essentials You have an array A of N elements.

// For each i = 1...N, you can do one of:

// Do nothing (pay 0 coins).

// Add A[i] to sum, increment x by 1 (pay 1 coin).

// Add (A[i]+x) to sum, increment x by 1 (pay 2 coins).

// For K=1 to 2N, find the maximum sum you can achieve, starting with K coins.

// Observation For each position, your choices affect: the current sum, the value of x, and the remaining coins.

// Stateful problem: choice at each step depends on history (x, coins spent).

// You need to efficiently keep track for all 1..2N values of K.

// Constraints allow O(N²) per test case (as ∑N ≤ 2000 over all testcases).

// Key DSA Idea: Dynamic Programming (DP)

// State Definition Let dp[i][k][x] be the maximum sum obtainable after the first i elements, having used k coins and incremented x x times so far.
// But, to optimize:

// At each i, iterating all possible K used so far, and all possible x (at most i).

// Realize that x can never be bigger than k (since every inc x costs at least 1 coin).

// But let's focus on a slightly more optimal representation:

// For each number of 1-coin actions (take1) and number of 2-coin actions (take2) up to i:

// x = take1 + take2

// coins_used = take1 * 1 + take2 * 2

// sum = sum of A selected by 1-coin + sum of A + x selected by 2-coin

// Realization For each subset of positions, for each j from 0 to i (how many picks of 1-coin and 2-coin actions), but this seems exponential.
// Alternative: DP by position, current coins spent, and current x.

// Efficient DP a) DP Definition Let dp[i][k][x] be the max sum after first i elements, using exactly k coins, and having incremented x x times.
// But to reduce memory and time:

// Since at position i, x can range from 0 to i

// and k can range from 0 to 2i

// b) DP Transition At step i:

// Do nothing: dp[i+1][k][x] = max(dp[i+1][k][x], dp[i][k][x])

// Pay 1 coin: dp[i+1][k+1][x+1] = max(dp[i+1][k+1][x+1], dp[i][k][x] + A[i])

// Pay 2 coins: dp[i+1][k+2][x+1] = max(dp[i+1][k+2][x+1], dp[i][k][x] + A[i] + x)

// c) Initialization dp = 0

// d) For Each K (1..2N) For each K, loop over all possible x and set answer[K] = max(dp[N][K][x]) (N: all elements processed)