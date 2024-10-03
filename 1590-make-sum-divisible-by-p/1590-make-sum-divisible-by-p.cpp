class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;
        for(int i : nums)
        totalSum += i;

        int rem = totalSum%p;
        if(rem == 0)
        return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        long sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            long a = sum%p;
            long b = (a - rem + p)%p;
            if(mp.find(b) != mp.end()){
                n = min(n, i - mp[b]);
            }
            mp[a] = i;
        }
        return n == nums.size() ? -1 : n;

    }
};
