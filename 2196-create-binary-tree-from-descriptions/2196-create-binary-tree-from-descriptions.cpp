class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> children;
        TreeNode* root = nullptr;
        for (auto i : descriptions)
        {
            if (!m[i[0]])
            {
                m[i[0]] = new TreeNode{i[0], nullptr, nullptr};
            }
            if (!m[i[1]])
            {
                m[i[1]] = new TreeNode{i[1], nullptr, nullptr};
            }
            if (i[2] == 1)
            {
                m[i[0]]->left = m[i[1]];
            }
            else {
                m[i[0]]->right = m[i[1]];
            }
            children.insert(i[1]);
        }
        for (auto i : descriptions)
        {
            if (children.find(i[0]) == children.end())
            {
                root = m[i[0]];
                cout << root;
                return root;
            }
        }
        return root;
    }
};