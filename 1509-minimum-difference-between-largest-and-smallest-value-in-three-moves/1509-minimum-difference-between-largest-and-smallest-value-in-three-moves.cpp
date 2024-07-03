class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n =  nums.size();
        int cnt =0;
        if(n<=4){
            return 0; // can change most elem to same num diff 0
        }
        sort(nums.begin(),nums.end());
        int l =0;
        int r = n-4;
        int minDiff = INT_MAX;
        while(cnt<4){
            int diff = abs(nums[l++]-nums[r++]);
            minDiff= min(minDiff,diff);
            cnt++;
        }
        return minDiff;
    }
};
