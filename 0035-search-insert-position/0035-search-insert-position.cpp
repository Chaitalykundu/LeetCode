class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n= nums.size();
        
        int ans; 
        int l=0, h=n, mid;
        
        if(target>nums[h-1]){
            return h;
        }
        while(l<=h){
            mid = (l+h)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target)
                l= mid+1;
            
            else if(nums[mid]>target)
                h=mid-1;
        }
        return l;
        
    }
};