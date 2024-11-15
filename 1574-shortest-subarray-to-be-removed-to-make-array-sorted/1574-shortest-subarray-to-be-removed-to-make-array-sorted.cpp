class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        int i = 0;
        while(i+1<n && arr[i+1]>=arr[i])
            i++;
        int j = n-1;
        while(j-1>=0 && arr[j-1]<=arr[j])
            j--;
        int ans = max(i,n-j);
        if(i==0 && j==n-1)
        {    
            if(arr[i]>arr[j])
                return n-1;
            return n-2;
        }
        if(i==n-1 && j==0)
            return 0;
        for(int k=0;k<=i;k++)
        {
            if(arr[k]<=arr[j])
                ans = max(ans,k+1+n-j);
            else
            {
                if(arr[k]>arr[n-1])
                {
                    ans = max(ans,k+1);
                    continue;
                }
                int index = lower_bound(arr.begin()+j, arr.end(), arr[k])-arr.begin();
                ans = max(ans,k+1+n-index);
            }
        }
        return (n-ans);
    }
};
