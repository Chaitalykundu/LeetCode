class Solution {
public:
    bool isValid(const std::vector<std::vector<int>>& grid, 
const int& row, const int& col)
    {
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
        {
            return true;
        }

        return false;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        std::array<int, 5> transformations = {0, 1 , 0, -1, 0};
        int returnVal = 0;

        for(int targetRow = 0; targetRow < grid.size(); targetRow++)
        {
            for(int targetCol = 0; targetCol < grid[0].size(); targetCol++)
            {
                if(grid[targetRow][targetCol] == 1)
                {
                    std::queue<std::pair<int, int>> rowToColQ;
                    rowToColQ.emplace(targetRow, targetCol);

                    grid[targetRow][targetCol] = -1;
                    bool canReachEdge = false;
                    int landCells = 1;

                    while(rowToColQ.empty() == false)
                    {
                        int curRow = rowToColQ.front().first;
                        int curCol = rowToColQ.front().second;
                        rowToColQ.pop();

                        for(int i = 1; i < transformations.size(); i++)
                        {
                            int row = curRow + transformations[i];
                            int col = curCol + transformations[i - 1];

                            if(isValid(grid, row, col) == false)
                            {
                                canReachEdge = true;
                            }
                            else
                            {
                                if(grid[row][col] == 1)
                                {
                                    grid[row][col] = -1;
                                    ++landCells;
                                    rowToColQ.emplace(row, col);
                                }
                            }
                        }
                    }

                    if(canReachEdge == false)
                    {
                        returnVal += landCells;
                    }
                }
            }
        }

        return returnVal;
    }
};