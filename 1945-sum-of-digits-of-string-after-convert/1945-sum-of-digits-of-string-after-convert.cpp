class Solution {
public:
    int getLucky(string s, int k) {
        string s1="";
        int sum=0;
       for(char &ch : s)
            {
                int num=ch-'a'+1;
                s1+=to_string(num);
            }
        while(k>0)
           {
            sum=0;
            for(char &c : s1)
            {
                sum+=c-'0';
            }
            s1=to_string(sum);
            k--;
        }
        return stoi(s1);
        
    }
};