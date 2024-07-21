class Solution {
public:
    vector<int> toposort(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> topo;
        int count = 0;
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            topo.push_back(u);
            count++;
            for (auto& it : adj[u]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qu.push(it);
                    
                }
            }
        }
        if (count != n) {
            return {};
        }
        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        vector<int> toposort_row = toposort(rowConditions, k);
        vector<int> toposort_col = toposort(colConditions, k);

        if (toposort_row.empty() || toposort_col.empty()) {
            return {};
        }

        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(toposort_row[i]==toposort_col[j])
                {
                    matrix[i][j]=toposort_row[i];
                }
            }
        }

        return matrix;
    }
};