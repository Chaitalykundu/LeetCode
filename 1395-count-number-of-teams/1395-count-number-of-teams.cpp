class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            int left_smaller = 0, left_greater = 0;
            int right_smaller = 0, right_greater = 0;
            
            // Count elements smaller and greater than rating[i] to the left
            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) {
                    ++left_smaller;
                } else if (rating[j] > rating[i]) {
                    ++left_greater;
                }
            }
            
            // Count elements smaller and greater than rating[i] to the right
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] < rating[i]) {
                    ++right_smaller;
                } else if (rating[j] > rating[i]) {
                    ++right_greater;
                }
            }
            
            // Form valid teams
            count += left_smaller * right_greater + left_greater * right_smaller;
        }
        
        return count;
    }
};