class Solution {
public:
    void dfs(vector<vector<int>> &graph, int &n, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n || graph[i][j] != 0) return;
        graph[i][j] = 1;
        dfs(graph, n, i + 1, j);
        dfs(graph, n, i - 1, j);
        dfs(graph, n, i, j + 1);
        dfs(graph, n, i, j - 1);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int multiplier = 3, ans = 0, graphSize = n * multiplier;
        vector<vector<int>> graph(graphSize, vector<int>(graphSize, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '/'){
                    int k = i * multiplier, l = j * multiplier + multiplier - 1, t = multiplier;
                    while(t--){
                        graph[k][l] = 1;
                        k++;
                        l--;
                    }
                }else if(grid[i][j] == '\\'){
                    int k = i * multiplier, l = j * multiplier, t = multiplier;
                    while(t--){
                        graph[k][l] = 1;
                        k++;
                        l++;
                    }
                }
            }
        }
        for(int i=0; i<graphSize; i++){
            for(int j=0; j<graphSize; j++) {
                if(graph[i][j] == 0){
                    dfs(graph, graphSize, i, j);
                    ans++;
                }
            }
        }
 return ans;
    }
};