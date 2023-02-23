class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Sort projects in order of capital (least capital -> most capital)
        vector<pair<int, int>> projects(profits.size());
        for (size_t i = 0; i < profits.size(); i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        // Keep track of highest profit project in priority queue
        priority_queue<int> best_profit;
        for (const auto& [cost, profit]: projects) {
            // If we can't afford this project, take highest profit until we can
            while (!best_profit.empty() && w < cost && k--) {
                w += best_profit.top(); best_profit.pop();
            }
            // No more projects can be conducted - return current capital
            if (!k || w < cost) return w;
            // Add project to priority queue
            best_profit.push(profit);
        }

        // All remaining projects are affordable - add the best ones
        while (k-- && !best_profit.empty()) {
            w += best_profit.top();
            best_profit.pop();
        }
        return w; 
    }
};