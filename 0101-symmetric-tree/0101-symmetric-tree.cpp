/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
    
        queue<TreeNode*> q;
        q.push(root -> left);
        q.push(root -> right);
    
        while(!q.empty()) {
            TreeNode* L = q.front();
            q.pop();

            TreeNode* R = q.front();
            q.pop();

            if(L == NULL && R == NULL) continue;

            if(L == NULL || R == NULL) return false;
            
            if(L -> val != R -> val) return false;

            q.push(L -> left);
            q.push(R -> right);
            q.push(L -> right);
            q.push(R -> left);
        }

        return true;
    }
};