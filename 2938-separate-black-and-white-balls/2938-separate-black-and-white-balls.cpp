class Solution {
public:
    long long minimumSteps(string s) {
        long long sum=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0'==0) {
            sum+=i-j;
            j++;}

        } 
        
        return sum;


        
    }
};
