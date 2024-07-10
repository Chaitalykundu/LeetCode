class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int depth = 0;
        for(auto &s: logs){
            if(s == "../"){
                depth -= (depth > 0);
            }
            else if(s != "./"){
                depth++;
            }
        }
        return depth;
    }
};