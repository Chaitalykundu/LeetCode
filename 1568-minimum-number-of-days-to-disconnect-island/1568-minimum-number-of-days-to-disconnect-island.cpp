#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &grid, int i, int j, int check)
    {
        if (i - 1 >= 0 && grid[i - 1][j] == check)
        {
            grid[i - 1][j] = check + 1;
            bfs(grid, i - 1, j, check);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == check)
        {
            grid[i][j - 1] = check + 1;
            bfs(grid, i, j - 1, check);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == check)
        {
            grid[i + 1][j] = check + 1;
            bfs(grid, i + 1, j, check);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == check)
        {
            grid[i][j + 1] = check + 1;
            bfs(grid, i, j + 1, check);
        }
    }

    int countIslands(vector<vector<int>> grid, int batk)
    {
        int temp = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == batk)
                {
                    grid[i][j] = batk + 1;
                    bfs(grid, i, j, batk);
                    temp++;
                }
            }
        }
        return temp;
    }

    int minDays(vector<vector<int>> &grid)
    {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
        int island = countIslands(grid, 1);
        if (island > 1 || island == 0)
        {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int b = countIslands(grid, 1);
                    if (b == 0 || b > 1)
                    {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
