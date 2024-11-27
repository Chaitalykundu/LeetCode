class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>dist(n,0);
        int count=0;
        map<int,list<int>>mp;
        for(int i=0;i<n-1;i++){
            mp[i].push_back(i+1);
        }
        for(int i=n-1;i>=0;i--){
            dist[i]=count;
            count++;
        }
        int i=0;
        vector<int>ans(queries.size());
        while(i<queries.size()){
            int u=queries[i][0];
            int v=queries[i][1];
            mp[u].push_back(v);
            dist[u]=min(dist[u],dist[v]+1);
            for(int j=u-1;j>=0;j--){
                for(auto t:mp[j]){
                    dist[j]=min(dist[j],dist[t]+1);
                }
            }
            ans[i]=dist[0];
            i++;
        }
        return ans;
    }
};
