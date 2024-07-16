class Solution {
public:
   TreeNode* solve(TreeNode* root , int p, int q){
        if(root == NULL) return NULL;
        if(root -> val == p || root -> val == q) return root;

        TreeNode* left  = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);

        if(left != NULL && right!=NULL) return root;
        
        if(left == NULL) return right;
        return left;

    }
    void desttoEnd(TreeNode* lca, int destVal,string &ans, string &dtoe){
        if(!lca) return;
        if(lca->val== destVal){
            dtoe = ans;
            return;
        }
        ans.push_back('L');
         desttoEnd(lca->left,destVal,ans,dtoe);
         ans.pop_back();
         ans.push_back('R');
         desttoEnd(lca->right,destVal,ans,dtoe);
          
          ans.pop_back();

    }

    void starttoEnd(TreeNode* lca, int startVal,string &ans, string &stoe){
        if(!lca) return;
        if(lca->val==startVal){
            stoe = ans;
            return;
        }
        ans.push_back('U');
         starttoEnd(lca->left,startVal,ans,stoe);
          starttoEnd(lca->right,startVal,ans,stoe);
          ans.pop_back();

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = solve(root,startValue,destValue);
        string stoe;
        string dtoe;
        string ans;
        starttoEnd(lca,startValue,ans,stoe);
        desttoEnd(lca,destValue,ans,dtoe);
        return stoe+dtoe;
    }
};