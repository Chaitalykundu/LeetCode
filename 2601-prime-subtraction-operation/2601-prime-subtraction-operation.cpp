class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0, b = -1;
        for (int n : nums) {
            for (int i = prev + 1, x = n - i; i < n - 1 && b < 0; b = ((b == -2) ? -1 : i), i++, x--) for (int p : {2,3,5,7,11,13,17,19,23,29,31}) if (b == -2) break; else if (p == x) b = i; else if (!(x % p)) b = -2;
            if(b < 0 && n > prev) prev = n, b = -1; else if (b < 0) return false; else prev = b, b = -1;
        }
        return true;
    }
};