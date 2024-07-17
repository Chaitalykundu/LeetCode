class Solution {
public:
    bool set[1001];
    void dfs(TreeNode* node, bool is_root,vector<TreeNode*> &ans){
        if(node == NULL) return;
        if(set[node->val]){
            dfs(node->left,true,ans);
            dfs(node->right,true,ans);
        }
        else{
            if(is_root) ans.push_back(node);
            TreeNode* leftNode = node->left;
            TreeNode* rightNode = node->right;
            if(node->left){
                if(set[node->left->val]){
                    node->left = NULL;
                }
            }
            if(node->right){
                if(set[node->right->val]){
                    node->right = NULL;
                }
            }
            dfs(leftNode,false,ans);
            dfs(rightNode,false,ans);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector< TreeNode* > ans;
        for(int num : to_delete){
            set[num] = true;
        }
        dfs(root,true,ans);
        return ans;
    }
};