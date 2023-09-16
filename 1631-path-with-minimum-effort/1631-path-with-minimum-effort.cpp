class Solution {
public:
    std::vector<int> DIR = {0, 1, 0, -1, 0};
    
    bool dfs(int r, int c, std::vector<std::vector<bool>>& visited, int threshold, const std::vector<std::vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        if (r == m - 1 && c == n - 1) return true; // Reach destination
        visited[r][c] = true;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + DIR[i];
            int nc = c + DIR[i + 1];
            
            if (nr < 0 || nr == m || nc < 0 || nc == n || visited[nr][nc]) continue;
            
            if (std::abs(heights[nr][nc] - heights[r][c]) <= threshold && dfs(nr, nc, visited, threshold, heights)) {
                return true;
            }
        }
        return false;
    }
    
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        int left = 0;
        int ans = 0;
        int right = 1e6;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
            
            if (dfs(0, 0, visited, mid, heights)) {
                right = mid - 1; // Try to find a better result on the left side
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
