class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> maxSum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            long long levelSum = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                levelSum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(maxSum.size() < k) maxSum.push(levelSum);
            else if(levelSum > maxSum.top()){
                maxSum.pop();
                maxSum.push(levelSum);
            }
        }
        return k > maxSum.size()? -1 : maxSum.top();
    }
};
