class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        
        int l=0, h=len-1, mid;
        
        while(l<=h){
            mid = (l+h)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};