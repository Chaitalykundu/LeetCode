class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            sum += skill[i];
        }
        long long teams = n / 2;
        if (sum % teams != 0)
            return -1;
        long long reqSum = sum / teams;
        sort(skill.begin(), skill.end());
        long long l = 0;
        long long r = n - 1;
        long long ans = 0;
        while (l <= r) {
            long long s = skill[l] + skill[r];
            if (s == reqSum) {
                ans += (skill[l] * skill[r]);
                l++;
                r--;
                teams--;
            } else if (s < reqSum) {
                l++;
            } else
                r--;
        }
        if (ans == 0 || teams!=0)
            return -1;
        return ans;
    }
};