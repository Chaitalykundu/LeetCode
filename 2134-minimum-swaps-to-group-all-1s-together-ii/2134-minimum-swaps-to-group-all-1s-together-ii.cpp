class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(auto i : nums){
            if(i == 1){
                count++;
            }
        }
        if(!count){
            return count;
        }
        int zero = 0, ans = INT_MAX, i = 0;
        for(int j = 0;j<2*n;j++){
            if(nums[j%n] == 0){
                zero++;
            }
            if(j >= count-1){
                ans = min(ans, zero);
                if(nums[i%n] == 0){
                    zero--;
                }
                i++;
            }
        }
        return ans;
    }
};