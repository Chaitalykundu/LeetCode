class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        std::unordered_map<int, int> mp;

        // Count the frequency of each element
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Iterate through the frequencies and calculate operations
        for (auto it : mp) {
            int val = it.second;

            // If the frequency is 1, it's not possible
            if (val == 1) {
                return -1;
            }

            // Calculate operations based on the frequency
            if (val % 3 == 0) {
                cnt += (val / 3);
            } else {
                // If the remainder is 1 or 2 after dividing by 3
                cnt += val / 3 + 1;
            }
        }

        return cnt;
    }
};