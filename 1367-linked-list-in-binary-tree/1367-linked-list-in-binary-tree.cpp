class Solution {
    bool match(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(head -> val == root -> val) return match(head -> next, root -> left) || match(head -> next, root -> right);
        return false;
    }
    void dfs(ListNode* head, TreeNode* root, bool &ans) {
        if(!root) return;
        if(root -> val == head -> val) ans = match(head, root);
        if(ans) return;
        dfs(head, root -> left, ans);
        dfs(head, root -> right, ans);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans = false;
        dfs(head, root, ans);
        return ans;
    }
};