class Solution {
public:
    int calc(vector<int>& pillar, string& s) {
        unordered_set<string> uniq;
        int prev = -1;
        for (int i = 0; i < pillar.size(); i++) {
            if (pillar[i] == 1) {
                string temp = "";
                for (int j = prev + 1; j <= i; j++)
                    temp += s[j];
                    if(uniq.find(temp)!=uniq.end()) return INT_MIN;
                uniq.insert(temp);
                prev = i;
            }
        }
        return uniq.size();
    }
    void find_ans(string& s, int& ans, vector<int>& pillar, int ind) {
        if (ind == s.size()) {
            ans = max(calc(pillar, s), ans);
            return;
        }
        find_ans(s, ans, pillar, ind + 1);
        pillar[ind] = 1;
        find_ans(s, ans, pillar, ind + 1);
        pillar[ind] = -1;
    }
    int maxUniqueSplit(string s) {
        vector<int> pillar(s.size(), -1);
        int ans = INT_MIN;
        find_ans(s, ans, pillar, 0);
        return ans;
    }
};
