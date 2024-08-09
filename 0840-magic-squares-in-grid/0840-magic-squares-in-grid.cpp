class Solution {
public:
    bool checkGrid(vector<vector<int>>& grid, int i, int j) {
        vector<int> check;
        check.push_back(grid[i - 1][j - 1]);
        check.push_back(grid[i - 1][j]);
        check.push_back(grid[i - 1][j + 1]);
        check.push_back(grid[i][j - 1]);
        check.push_back(grid[i][j]);
        check.push_back(grid[i][j + 1]);
        check.push_back(grid[i + 1][j - 1]);
        check.push_back(grid[i + 1][j]);
        check.push_back(grid[i + 1][j + 1]);
        sort(check.begin(), check.end());
        for (int k = 1; k <= 9; k++) {
            if (check[k - 1] != k)
                return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 5 && checkGrid(grid, i, j)) {
                    int a = grid[i - 1][j - 1] + grid[i - 1][j] +
                            grid[i - 1][j + 1];
                    int b = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                    int c = grid[i + 1][j - 1] + grid[i + 1][j] +
                            grid[i + 1][j + 1];
                    int d = grid[i - 1][j - 1] + grid[i][j - 1] +
                            grid[i + 1][j - 1];
                    int e = grid[i - 1][j] + grid[i][j] + grid[i + 1][j];
                    int f = grid[i - 1][j + 1] + grid[i][j + 1] +
                            grid[i + 1][j + 1];
                    int g =
                        grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
                    int h =
                        grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1];
                    if (a == 15 && b == 15 && c == 15 && d == 15 && e == 15 &&
                        f == 15 && g == 15 && h == 15)
                        ans++;
                }
            }
        }
        return ans;
    }
};