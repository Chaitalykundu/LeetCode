class Solution {
public:
    int N;
    int solve(vector<int>& p, int idx, int M, int turn, vector<vector<vector<int>>> &dp)
    {
        if(N <= idx) return 0;
        if(dp[idx][M][turn] != -1) return dp[idx][M][turn];

        int ans = turn ? INT_MIN : INT_MAX, sum = 0;
        for(int jdx = idx ; jdx < N && jdx < idx + 2*M; jdx++)
        {
            sum += p[jdx];
            if(turn)
            {
                ans = max(ans, solve(p, jdx+1, min(N, max(M, jdx-idx+1)), !turn, dp) + sum);
            }else {
                ans = min(ans, solve(p, jdx+1, min(N, max(M, jdx-idx+1)), !turn, dp));
            }
        }

        return dp[idx][M][turn] = ans;
    }
    int stoneGameII(vector<int>& p) {
        N = p.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (N+1, vector<int> (2, -1)));
        return solve(p, 0, 1, 1, dp);
    }
};