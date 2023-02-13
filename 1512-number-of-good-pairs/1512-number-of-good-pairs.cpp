class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp(101);
        
        int c=0;
        for(int i=0;i<n;i++){
            c+=temp[nums[i]]++;
        }
        
        return c;
    }
};