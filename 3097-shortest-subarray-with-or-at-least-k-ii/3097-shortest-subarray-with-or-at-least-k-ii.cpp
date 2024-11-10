class Solution 
{
public:
    int minimumSubarrayLength(vector<int>& nums, int k1) 
    {
        int n=nums.size();
        int bit[32];
        int ornum=0;
        int i,j;
        i=j=0;
        int ans=INT_MAX;
        while(j<n)
        {
            int num=nums[j];
            ornum|=num;
            int abc=1;
            for(int k=0;k<32;k++)
            {
                if(num&abc)
                    bit[k]++;
                abc=abc<<1;
            }
            if(ornum<k1)
                j++;
            else
            {
                while(i<=j and ornum>=k1)
                {
                    ans=min(ans,j-i+1);
                    num=nums[i];
                    abc=1;
                    for(int k=0;k<32;k++)
                    {
                        if(num&abc)
                        {
                            bit[k]--;
                            if(bit[k]==0)
                                ornum^=abc;
                        }
                        
                        abc=abc<<1;
                    }
                    i++;
                    }
                j++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
