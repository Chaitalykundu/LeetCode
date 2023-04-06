class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    function<void(int,int)>DFS=[&](int i,int j)->void
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==1)
        {
            return;
        }
        grid[i][j]=1;
        DFS(i+1,j);
        DFS(i-1,j);
        DFS(i,j+1);
        DFS(i,j-1);
    };
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i==0 or j==0 or i==n-1 or j==m-1)
            {
                DFS(i,j);
            }
        }
    }
    
    int closedIslands=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]==0)
            {
                closedIslands++;
                DFS(i,j);
            }
        }
    }
    return closedIslands;
}
    
};