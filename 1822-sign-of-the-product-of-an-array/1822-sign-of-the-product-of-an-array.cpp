class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int n = nums.size();
        
        long long int product = 1;
        
        for(int i=0;i<n;i++){
            product*=nums[i];
            
            if(product==0)
            return 0;
            
            else if(product>0)
                product = 1;
            else
                product = -1;
        }
        
        
        if(product>0)
            return 1;
        else
            return -1;
    }
};