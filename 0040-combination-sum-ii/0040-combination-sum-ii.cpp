class Solution {
public:
    void solve(int i,vector<vector<int>>& ans,vector<int>& candidates,vector<int>& ds, int target){
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int ind=i;ind<candidates.size()&&target>=candidates[ind];++ind){
            if(ind==i ||candidates[ind]!=candidates[ind-1]){
                ds.push_back(candidates[ind]);
                solve(ind+1,ans,candidates,ds,target-candidates[ind]);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        solve(0,ans,candidates,ds,target);
        return ans;
    }
};