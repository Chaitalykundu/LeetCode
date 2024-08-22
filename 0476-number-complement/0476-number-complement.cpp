class Solution {
public:
    int findComplement(int num) {
        int ans = 0, place = 0;
        while(num > 0)
        {
            int n = (num % 2) ^ 1;
            ans |= (n << place++);
            num /= 2;
        }
        return ans;
    }
};