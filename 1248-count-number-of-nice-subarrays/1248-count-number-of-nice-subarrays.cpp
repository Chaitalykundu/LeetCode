class Solution {
public:
    int n;

    // Helper function to count subarrays with at most k odd numbers
    int niceLessEqualK(vector<int>& nums, int k){
        int odds=0, cnt=0;
        for(int l=0, r=0; r<n; r++){
            int x=nums[r];
            odds+=(x&1);
            while(odds>k){
                int y=nums[l];
                odds-=(y&1);
                l++;
            }
            cnt+=(r-l+1); // # of subarrays ending at r with at most k odd numbers
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        return niceLessEqualK(nums, k)-niceLessEqualK(nums, k-1);
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();