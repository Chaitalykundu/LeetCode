class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        
        int sum = 0;
        long long int ans = 0;
        long long int windowsum=0;
        for(int i=0;i<k;i++)
        {
            windowsum+=nums[i];
            m[nums[i]]++;
        }
        int i = 0;
        int j = k-1;
        while(j<nums.size())
        {
            if(m.size()==k)
            {
                ans=max(ans,windowsum);
            }
            m[nums[i]]--;
            if(m[nums[i]]==0)
            {
                m.erase(nums[i]);
            }
            windowsum-=nums[i];
            i++;
           j++;
            if (j < nums.size()) 
            {
                windowsum += nums[j];
                m[nums[j]]++;
            }
        }
        return ans;
    } 
    };
