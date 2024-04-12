class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int L = 0;
        int R = n - 1;
        int ans = 0;
        int mx = 0;
        while(L < R) {
            
            int water = mx - min(height[L], height[R]);
            if(water > 0) {
                ans += water;
            }
            
            if(height[L] < height[R]) {
                mx = max(mx, height[L++]);
            } else {
                mx = max(mx, height[R--]);
            }
        }

        return ans;
    }
};