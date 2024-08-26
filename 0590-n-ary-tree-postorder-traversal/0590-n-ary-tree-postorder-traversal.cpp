class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> result;
        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            result.push_back(node->val);

            // Push all children of the current node to the stack
            for (size_t i = 0; i < node->children.size(); ++i) {
                Node* child = node->children[i];
                stk.push(child);
            }
        }

        // Since we want postorder, reverse the result
        reverse(result.begin(), result.end());
        return result;
    }
};