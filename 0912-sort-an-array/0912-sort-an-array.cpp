class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        mergesort(nums,0,nums.size()-1);
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
    void mergesort(vector<int> &arr,int lb,int ub){
        if(lb >= ub){
            return;
        }
        int mid = (lb + ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
    void merge(vector<int> &arr,int lb,int mid,int ub){
        vector<int> temp;
        int left = lb;
        int right = mid+1;

        while(left <= mid && right <= ub){
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= ub) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = lb; i <= ub; i++) {
            arr[i] = temp[i - lb];
        }
    }
};