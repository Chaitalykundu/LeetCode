class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int ele : nums) {
            max_or |= ele;
        }

        int ans = 0;
        int curr = 0;
        int n = (int) pow(2, nums.size());
        int temp;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            curr = 0;
            temp = i;
            counter = 0;

            while (temp > 0) {
                if (temp & 1) {
                    curr |= nums[counter];
                }
                temp >>= 1;
                counter++;
            }
            if (curr == max_or) {
                ans++;
            }
        }

        return ans;
    }
};