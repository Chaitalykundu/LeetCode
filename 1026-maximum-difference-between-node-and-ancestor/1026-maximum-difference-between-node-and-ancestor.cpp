class Solution {
public:
    int ans;
    void solve(TreeNode* root , int maxi , int  mini){
        if(root==NULL){
            ans = max(ans , abs(maxi - mini));
            return;
        }
        maxi = max(maxi , root->val);
        mini = min(mini, root->val);
        solve(root->left , maxi , mini);
        solve(root->right , maxi , mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        solve(root , root->val , root->val);
        return ans;
    }
};