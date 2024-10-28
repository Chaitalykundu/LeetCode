class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> a(mx+1);
        for(auto i: nums) a[i]=1;
        int cnt = 0;
        for(auto i:nums)
        {
            int x = 0;
            long long val = i;
            while(val<=mx && a[val])
            {
                val=val*val;
                x++;
            }
            cnt = max(cnt, x);

        }

        if(cnt == 1)
            return -1;

        return cnt;
    }
};
