class Solution {
public:
    //dfs
    int solveDFS(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        visited[row][col] = 1;
        int dx[]={0,-1,1};
        int dy[]={1,1,1};
        for(int i =0;i<3;i++){
            int nrow = row+dx[i];
            int ncol = col+dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=1 && grid[nrow][ncol]>grid[row][col]){
                visited[nrow][ncol]=1;
                count=max(count,1+solveDFS(nrow, ncol, visited, grid));
            }
        }
        return count;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            // for(int j=0;j<m;j++){
                count=max(count,solveDFS(i,0,visited,grid));
                // count++;
            // }
        }
        return count;
    }
};
