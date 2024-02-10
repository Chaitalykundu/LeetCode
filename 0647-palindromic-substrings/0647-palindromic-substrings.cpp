class Solution {
public:
    bool check_pal(string &s, int l, int r){
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(check_pal(s, i, j)) cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
};