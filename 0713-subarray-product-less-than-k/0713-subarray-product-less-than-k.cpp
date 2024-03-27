#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1) return 0; // edge case
        unsigned long long prod=1;
        int n=nums.size(), l=0, cnt=0;
        for(int r=0; r<n; r++){
            prod*=nums[r];
            while (prod >= k)
                prod/=nums[l++];
            cnt+=(r-l+1);// # of valid subarrys ending at r
        }
        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();