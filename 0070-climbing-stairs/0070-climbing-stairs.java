class Solution {
    public int climbStairs(int n) {
        int[] dp = {1, 1};
        for (int i = 1; i < n; i++) {
            int one = dp[0];
            dp[0] = dp[1];
            dp[1] = one + dp[0];
        }
        return dp[1];  
    }
}