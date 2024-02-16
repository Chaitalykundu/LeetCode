class Solution {
public:
    // time/space: O(nlogn)/O(n)
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // count the frequency for each integer
        unordered_map<int, int> freq;
        for (auto& num : arr) freq[num]++;

        // put {frequency, integer} into a priority queue, and keep the least frequency on the top
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto& [num, f] : freq) pq.push({f, num});

        // remove exactly `k` elements
        while (k > 0) {
            auto& top = pq.top();
            int f = top[0], num = top[1];
            pq.pop();

            if (k >= f) {
                k -= f;
            }
            else {
                k = 0;
                pq.push({f - k, num});
            }
        }

        return pq.size();
    }
};