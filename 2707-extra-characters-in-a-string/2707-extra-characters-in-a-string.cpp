class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        vector<int> dp(s.size() + 1, 0); // each cell represents the maximum number of 0 ~ i matched charactors.
        for(auto& str: dictionary) {
            dict.insert(str);
        }
        for(int l = 0; l < s.size(); ++l) {
            for(int r = l; r < s.size(); ++r) {
                int len = r - l + 1;
                if(dict.count(s.substr(l, len))) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + len);
                } else {
                    dp[r + 1] = max(dp[r + 1], dp[r]);
                }
            }
        }
        return s.size() - dp[s.size()];
    }
};