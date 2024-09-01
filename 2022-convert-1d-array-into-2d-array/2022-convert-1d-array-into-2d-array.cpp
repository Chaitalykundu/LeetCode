class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>result;
        int x = original.size();
        if(m*n != x) return result;
        result = vector<vector<int>>(m,vector<int>(n));
        int y=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j] = original[y];
                y++;
            }
        }
        return result;
    }
};