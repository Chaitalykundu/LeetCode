class Solution {
public:
    void dfs(int node, int& ans, vector<vector<pair<int, bool>>>& destinations, vector<bool>& done){
        done[node] = 1;
        for(auto& [v, dis] : destinations[node]){
            if(done[v] == 0){
                if(dis == 0) ans++;
                dfs(v, ans, destinations, done);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> destinations(n);
        for(auto city : connections){
            destinations[city[1]].push_back({city[0], 1});
            destinations[city[0]].push_back({city[1], 0});
            //whether the city[1] is the destination of city[0]
        }
        vector<bool> done(n, 0);
        int ans = 0;
        dfs(0, ans, destinations, done);
        return ans;  
    }
};