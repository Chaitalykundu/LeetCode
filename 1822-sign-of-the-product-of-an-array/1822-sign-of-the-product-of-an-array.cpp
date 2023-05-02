class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int n = nums.size();

        int ans=1;
        
        for(auto i : nums){
            if(i>0)
                ans *=1;
            else if(i<0)
                ans *=-1;
            else
                return 0;
        }
        return ans;
    }
};