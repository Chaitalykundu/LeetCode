class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin() , nums.end());
        int size = 0;
        int maxSize = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == maxNum){
                size++;
                maxSize = max(size , maxSize);
            }
            else{
                size = 0;
            }
        }
        return maxSize;
    }
};