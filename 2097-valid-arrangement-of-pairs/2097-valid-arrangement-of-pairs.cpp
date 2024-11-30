class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int mx = INT_MIN;
        for (auto& pair : pairs) {
            mx = max({mx, pair[0], pair[1]});
        }

        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> out;
        unordered_map<int, int> in;

        // brute force start from every point and see if the whole graph gets visited (rejected)
        // might be the approach fix the start and end point based on indegree and outdegree :) start mil gaya end bana lenge easy :)
        // to be a start node i should always have one extra out going node think yourself this makes sense.....
        for (auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            out[pair[0]]++;
            in[pair[1]]++;
        }

        int start_node = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (out[node] - in[node] == 1) {
                start_node = node;
                break;
            }
        }
        
        vector<vector<int>> result;
        //dfs
        dfs(start_node, graph, result);

        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<vector<int>>& result) {
        while (!graph[node].empty()) {
            int next = graph[node].back();
            graph[node].pop_back();
            dfs(next, graph, result);
            result.push_back({node, next});
        }
    }
};
