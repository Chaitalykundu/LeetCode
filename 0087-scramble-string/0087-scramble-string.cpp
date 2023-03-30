class Solution {
public:
    bool solve(string s1,string s2,unordered_map<string,int>& dp){
if(s1.length() != s2.length()) return false;
if(s1.compare(s2) == 0) return true;
int n = s1.length();
string s = s1 + " " + s2;
if(dp.find(s) != dp.end()) return dp[s];
bool flag = false;
for(int i = 1;i<n;i++){
bool cond1 = solve(s1.substr(0,i),s2.substr(n-i,i),dp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),dp);
bool cond2 = solve(s1.substr(0,i),s2.substr(0,i),dp) && solve(s1.substr(i,n-i),s2.substr(i,n-i),dp);
flag = cond1 || cond2 ;
if(flag == true) break;
}
return dp[s] = flag;
}
bool isScramble(string s1, string s2) {
int n= s1.length();
int m = s2.length();
if(n != m) return false;
if(n == 0 && m == 0) return false;
unordered_map<string,int> dp;
return solve(s1,s2,dp);  
    }
};