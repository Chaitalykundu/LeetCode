class Solution 
{
public:
    long findsteps(long curr, long n) 
    {
        long steps = 0, first = curr, last = curr;
        while (first <= n) 
        {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) 
    {
        long cur=1;
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        k--;
        long steps;
        while(k>0)
        {
            steps=findsteps(cur,n);
            if(steps<=k)
            {
                cur++;
                k-=steps;
            }
            else
            {
                cur*=10;
                k--;
            }
        }
        return cur;
    }
};