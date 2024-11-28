class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        vector<pair<int, int>> diffs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // A deque to perform 0-1 BFS
        deque<pair<int, int>> in_progress;

        vector<vector<int>> distance(n_rows, vector<int>(n_cols, INT_MAX));
        
        // Start from the top-left corner
        in_progress.push_front({0, 0});
        distance[0][0] = 0;

        // Perform BFS
        while (!in_progress.empty()) {
            auto [i, j] = in_progress.front();
            in_progress.pop_front();

            // Check all 4 possible directions
            for (const auto& [di, dj] : diffs) {
                int new_i = i + di;
                int new_j = j + dj;

                if (new_i >= 0 && new_i < n_rows && new_j >= 0 && new_j < n_cols) {
                    // Calculate new distance
                    int new_distance = distance[i][j] + grid[new_i][new_j];

                    // If a shorter path to this cell is found, update it
                    if (new_distance < distance[new_i][new_j]) {
                        distance[new_i][new_j] = new_distance;

                        // Push to front or back of deque based on cell value
                        if (grid[new_i][new_j] == 0) {
                            in_progress.push_front({new_i, new_j});
                        } else {
                            in_progress.push_back({new_i, new_j});
                        }
                    }
                }
            }
        }

        return distance[n_rows - 1][n_cols - 1];
    }
};