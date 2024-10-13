class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int temp = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], {i, 0}});
            temp = max(temp, nums[i][0]);
        }
        vector<int> ans = {pq.top().first, temp};
        while (true) {
            auto [i, j] = pq.top(); pq.pop();
            if (temp - i < ans[1] - ans[0]) ans = {i, temp};
            if (j.second + 1 == nums[j.first].size()) break;
            int nextVal = nums[j.first][j.second + 1];
            pq.push({nextVal, {j.first, j.second + 1}});
            temp = max(temp, nextVal);
        }
        return ans;
    }
};