class Solution {
public:
    vector<int> kmp(string s){
        int n=s.size();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int prev=lps[i-1];
            while(prev>0 && s[i]!=s[prev]) prev=lps[prev-1];
            lps[i] = prev + (s[i]==s[prev]?1:0); 
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        //O(N) or O(Nlogn)-> kmp algorithm
        string rev=s;
        reverse(rev.begin(),rev.end());
        string s2=s+'#'+rev;
        vector<int>lps=kmp(s2);

        string ans="";
        int len=lps.back();

        string palindromic=s.substr(len);
        reverse(palindromic.begin(),palindromic.end());
        ans=palindromic+s;
        return ans;
    }
};