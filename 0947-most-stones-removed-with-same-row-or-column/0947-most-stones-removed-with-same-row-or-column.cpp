class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0,maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        unordered_map<int,int>stoneNodes;
        DisjointSet ds(maxRow+maxCol+1);
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=maxRow+1+it[1];
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first)cnt++;
        }
        return n-cnt;
        
    }
};