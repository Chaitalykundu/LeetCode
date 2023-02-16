Using recursion and max

```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```
&nbsp;

Using recursion and conditions

```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
    
        int depthOfLeft = maxDepth(root->left);
        int depthOfRight = maxDepth(root->right);
        
        if(depthOfLeft>depthOfRight)
            return depthOfLeft + 1;
        return depthOfRight + 1;
    }
};
```
