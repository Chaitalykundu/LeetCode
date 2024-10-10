class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> stack;  // Monotonic decreasing stack
        int n = nums.size();
        
        // Step 1: Build the stack with decreasing elements' indices
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[i] < nums[stack.back()]) {
                stack.push_back(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end of the array and calculate the maximum width
        for (int j = n - 1; j >= 0; --j) {
            while (!stack.empty() && nums[j] >= nums[stack.back()]) {
                maxWidth = max(maxWidth, j - stack.back());
                stack.pop_back();  // Try to maximize the ramp width for this j
            }
        }
        
        return maxWidth;
    }
};
