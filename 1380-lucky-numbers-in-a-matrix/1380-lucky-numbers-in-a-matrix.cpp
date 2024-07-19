class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n), col(m), ans;

        for (int i = 0; i < n; ++i) {
            row[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }

        for (int i = 0; i < m; ++i) {
            int m1 = -1;
            for (int j = 0; j < n; ++j) {
                m1 = max(m1, matrix[j][i]);
            }
            col[i] = m1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};