class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        std::set<std::pair<int, int>> visited;
        int count = 0;

        auto dfs = [&](int r, int c, auto&& dfs_ref) -> bool {
            // Check boundaries
            if (r < 0 || r >= rows || c < 0 || c >= cols) return true;

            // Check if the current cell is water or already visited
            if (grid2[r][c] == 0 || visited.find({r, c}) != visited.end()) return true;

            // Mark the cell as visited
            visited.insert({r, c});

            // If the corresponding cell in grid1 is water, it's not a sub-island
            bool isSubIsland = grid1[r][c] == 1;

            // Explore all 4 directions
            isSubIsland = dfs_ref(r + 1, c, dfs_ref) & isSubIsland;
            isSubIsland = dfs_ref(r - 1, c, dfs_ref) & isSubIsland;
            isSubIsland = dfs_ref(r, c + 1, dfs_ref) & isSubIsland;
            isSubIsland = dfs_ref(r, c - 1, dfs_ref) & isSubIsland;

            return isSubIsland;
        };

        // Check each cell in grid2
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the cell is part of an island in grid2 and hasn't been visited
                if (grid2[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                    // If the entire island is a sub-island, increase the count
                    if (dfs(i, j, dfs)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
