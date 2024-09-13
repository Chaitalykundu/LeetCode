class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorAllElements;
        vector<int> result;
        
        // Build prefix XOR array
        xorAllElements.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            xorAllElements.push_back(xorAllElements[i - 1] ^ arr[i]);
        }

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            if (l == 0) {
                result.push_back(xorAllElements[r]);
            } else {
                result.push_back(xorAllElements[r] ^ xorAllElements[l - 1]);
            }
        }

        return result;
    }
};