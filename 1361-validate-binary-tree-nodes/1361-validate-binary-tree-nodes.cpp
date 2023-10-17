class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // step 1:
        // so, first thing is there should be only one root for a tree
        // root is the node with no parent, so we will find such possible roots
        // count of such possible roots must be one
        unordered_set<int> roots;
        for(int& i: leftChild)   roots.insert(i);
        for(int& j: rightChild) roots.insert(j);
        int count = 0;
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(roots.find(i) == roots.end()) {
                count++;
                root = i;
                if(count > 1)
                    return false;
            }
        }
        if(root == -1)
            return false;
        // step 2:
        // now, performing bfs from root, cycle can be found using vis array
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(root);
        vis[root] = true;
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            if(leftChild[i] != -1) {
                if(vis[leftChild[i]])
                    return false;
                vis[leftChild[i]] = true;
                q.push(leftChild[i]);
            }
            if(rightChild[i] != -1) {
                if(vis[rightChild[i]])
                    return false;
                vis[rightChild[i]] = true;
                q.push(rightChild[i]);
            }
        }
        // step 3:
        // now, checking whether all nodes are visited or not
        for(int i = 0; i < n; i++)
            if(!vis[i])
                return false;
        return true;
    }
};