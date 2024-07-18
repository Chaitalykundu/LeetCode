class Solution {
public:
    int ans = 0;
    vector<int>  solve(TreeNode* root, int dis)
    {
         if(root == NULL) return {};
         if(root->left == NULL && root->right == NULL) return {1};
         vector<int> l = solve(root->left, dis);
         vector<int> r = solve(root->right, dis);
         int n = l.size(), m = r.size();
         for(int i=0; i<n; i++)
         {
            int temp = dis - l[i];
            auto it = upper_bound(r.begin(), r.end(), temp) - r.begin();
            it--;
            ans += it - 0 + 1;
         }
         for(auto it:r)
         l.push_back(it);
         sort(l.begin(), l.end());
         for(auto &it:l)
         it += 1;
         return l;
    }
    int countPairs(TreeNode* root, int distance) {
        
        solve(root, distance);

        return ans;
    }
};