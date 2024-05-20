class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        
        int total = 0;
        
        // number of subset = 2^n = 1<<n
        
        for(int i=0;i<(1<<n);i++){
            int current_total = 0;
            for(int j=0;j<n;j++){
                if(i & (1<<j))
                    current_total^=nums[j];
                
            }
            total += current_total;
        } 
        return total;
    }
};