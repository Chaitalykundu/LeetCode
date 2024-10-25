class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<string>ans;

        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        
        for(int i=1;i<n;i++){
            int sz=ans.back().size();

            if(folder[i].substr(0,sz)!=ans.back() || folder[i][sz]!='/'){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
