class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20> xorSum(0);
        for(int x: nums){
            xorSum^=x;
        }
        xorSum ^=k;
 
        return xorSum.count();
    }
};
