class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>in(n,0);
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                if(ans!=-1){
                    return -1;
                }
                ans=i;
            }
        }
        return ans;
    }
};
