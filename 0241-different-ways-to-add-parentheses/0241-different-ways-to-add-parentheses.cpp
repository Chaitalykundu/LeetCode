class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // 1. Create an `unordered_map` for memoization of 
        // repeating sub-problems. 
        unordered_map<string, vector<int>> dp;

        // Auxillary function for recursive calls.
        function<vector<int>(string)> helper = [&](string exp) -> vector<int> {
            // Base conditions.
            if (dp.count(exp)) return dp[exp];
            if (exp.size()<3) return {stoi(exp)};

            vector<int> ans;
            for (int i=0; i<exp.size(); i++) {
                char c = exp[i];
                if (c == '+' || c == '-' || c == '*') {
                    // 2. Break down the string at each operator 
                    // into `left` and `right`.
                    // 2.1. Both `left` and `right` are now valid 
                    // expressions and can be evaluated to have solutions. 
                    vector<int> left = helper(exp.substr(0, i));
                    vector<int> right = helper(exp.substr(i+1));

                    // 2.2. Get all the possible evaluations for 
                    // `left` and `right` and create all possible 
                    // combinations using the current operator. 
                    for (int& a: left) {
                        for (int& b: right) {
                            if (c == '+') ans.push_back(a + b);
                            else if (c == '-') ans.push_back(a - b);
                            else ans.push_back(a * b);
                        }
                    }
                }
            }

            // 3. Memoize the solution for the current `expression`
            dp[exp] = ans;

            // 4. Return the result vector. 
            return ans;
        };

        return helper(expression);
    }
};