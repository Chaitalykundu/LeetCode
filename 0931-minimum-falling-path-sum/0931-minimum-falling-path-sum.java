class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        if(n == 1) return matrix[0][0];
        int[] dp = new int[n];
        for(int i = 0; i < n; i++) {
          dp[i] = matrix[0][i];  
        }
        for(int i = 1; i < n; i++) {
            int[] temp = new int[n];
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    temp[j] = matrix[i][j] + Math.min(dp[0], dp[1]);
                } else if(j == n - 1) {
                    temp[j] = matrix[i][j] + Math.min(dp[n - 1], dp[n - 2]);
                } else {
                    temp[j] = matrix[i][j] + Math.min(dp[j] ,Math.min(dp[j - 1], dp[j + 1]));
                }
            }
            dp = temp;
        }
        int result = Integer.MAX_VALUE;
        for(int e: dp) {
            result = Math.min(result, e);
        }
        return result;
    }
}