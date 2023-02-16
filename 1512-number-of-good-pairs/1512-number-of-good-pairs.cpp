class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp(1000);
        
        int c=0;
        
        // here num means the number of every index one by one
        
        for(int num:nums)
            c+= temp[num]++;
        
        // alternative
        
//         for(int i=0;i<n;i++){
//             c+=temp[nums[i]]++;
//         }
        
        return c;
    }
};


/*
 T.C = O(n)
*/