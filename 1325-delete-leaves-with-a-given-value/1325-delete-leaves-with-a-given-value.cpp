#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    using node2 = tuple<TreeNode*, TreeNode*, bool>; // Node, parent & visited flag
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        vector<node2> stack = {{root, NULL, 0}};

        while (!stack.empty()) {
            auto [node, parent, visited] = stack.back();
            stack.pop_back();

            if (!visited) {
                // Mark the node as visited & repush
                stack.emplace_back(node, parent, 1);

                // Push right and left children onto the stack
                if (node->right) 
                    stack.emplace_back(node->right, node, 0);
                if (node->left) 
                    stack.emplace_back(node->left, node, 0);
            } 
            else {
                // node is a leaf and its value==target, remove it
                if (!node->left && !node->right && node->val==target) {
                    if (parent) {
                        if (parent->left == node) 
                            parent->left = NULL;
                        else if (parent->right == node) 
                            parent->right = NULL; 
                        delete node; //no memory leaking 
                    }
                    else 
                        root=NULL;//no parent must be root, cannot be deleted
                }
            }
        }

        return root;
    }
};