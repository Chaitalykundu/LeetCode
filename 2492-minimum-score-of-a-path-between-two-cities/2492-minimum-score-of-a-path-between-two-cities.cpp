class Solution {
public:
    #define ll long long
    vector<ll>rank,parent,size;
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void justUnion(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        parent[ulp_u] = ulp_v;
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
         if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }


    int minScore(int n, vector<vector<int>>& roads) {
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i <= n;i++){
            parent[i] = i;
            size[i] = i;
        }
        for(ll i = 0;i < roads.size();i++){
            justUnion(roads[i][0],roads[i][1]);
        }
        int ans = INT_MAX;
        for(ll i = 0;i < roads.size();i++){
            if(findUPar(roads[i][0]) == findUPar(1)){
                ans = min(ans,roads[i][2]);
            }
        }
        return ans;
    }
};