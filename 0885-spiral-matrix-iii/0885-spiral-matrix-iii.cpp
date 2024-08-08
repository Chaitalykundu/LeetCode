class Solution {
public:
    bool isValid(int rows, int cols, int rStart, int cStart){
        return ((rStart >= 0) && (rStart < rows) && (cStart >= 0) && (cStart < cols));
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> answer;

        int val =  rows * cols;
        int size = 0;

        int max = 1;
        char dir = 'r';
        int x = 1;
        while(size < val){
            if((dir == 'l') && (x == (max+1))) x--;
            else{
            if(isValid(rows, cols, rStart, cStart)){
                answer.push_back({rStart, cStart});
                size++;
                }
            }

            if(dir == 'l') {
                if(x) { cStart--; x--;}
                else { dir = 'u'; x = max;}
            }
            if(dir == 'u') {
                if(x) { rStart--; x--;}
                else { dir = 'r';  max++; x = max;}
            }
            if(dir == 'r') {
                if(x) { cStart++; x--;}
                else { dir = 'd'; x = max;}
            }
            if(dir == 'd') {
                if(x) { rStart++; x--;}
                else { dir = 'l'; max++; x = max+1;}
            }
        }

        return answer;
    }
};