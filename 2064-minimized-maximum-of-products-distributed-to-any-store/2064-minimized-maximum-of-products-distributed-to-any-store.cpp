class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxEle = *max_element(quantities.begin(), quantities.end());

        int sz = quantities.size(), start = 1, end = maxEle, ans = INT_MAX, mid;

        while(start <= end){
            mid = start + (end-start)/2;
            int temp = 0;
            for(int i=0; i<sz; i++) temp += (quantities[i]+mid - 1)/mid;
            if(temp <= n) {
                ans = mid;
                end = mid-1;
            }  
            else start = mid+1;
        }

        return ans == INT_MAX ? maxEle : ans;
    }
};