class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int c=0,j=0;
                    
        for(int i=0;i<n;i++){
            if(nums[i] == nums[j])
                c+= i-j;
            else
                j=i;
        }
        
        return c;
    }
};


/*

    T.C = O(n(log(n)))

*/