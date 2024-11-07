class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int n = candidates.size(),ans = 0;
        
        //As per constrains candidates[i] <= 10^7 which can have max 24 bit 0 - 23
        for(int i=0; i < 24; i++)
        {
            int cnt = 0;

            //In thisloop we are interested in finding the largest combination of numbers whose AND is greater than 0.
            for(int candidate : candidates)
            { 
                cnt += candidate >> i & 1 ; 
            }

            //current largest combination of numbers whose AND is greater than 0.
            ans = max(ans,cnt);
        }
        return ans;
    }
};
