class Solution {
    int findK(int x, int mB) {
        int k = 0;
        for (int i = 0; i < mB; i++) {
            int currPower = 1 << i;

            int set = x & currPower;

            if (!set) {
                k = k ^ currPower;
            }
        }

        return k;
    }

public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0, n = nums.size();
        ;
        vector<int> ans;

        for (auto i : nums) {
            x = x ^ i;
        }

        for (int i = n - 1; i >= 0; i--) {

            int k = findK(x, maximumBit);

            ans.push_back(k);

            x = x ^ nums[i];
        }

        return ans;
    }
};
