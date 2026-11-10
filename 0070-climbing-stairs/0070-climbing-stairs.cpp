class Solution {
public:
    vector<int> dp;

    int backtrack(int n) {
        if (n == 0)
            return 1;

        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = backtrack(n - 1) + backtrack(n - 2);
    }

    int climbStairs(int n) {

        dp.assign(n + 1, -1);

        return backtrack(n);
    }
};