class Solution {
public:
        vector<int> parent, group_size;

    // Recursive function to find the parent of a node.
    int find_parent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find_parent(parent[n]);
    }

    // Function to merge two groups.
    void merge(int a, int b) {
        // Find the parents of the nodes.
        int parent_a = find_parent(a);
        int parent_b = find_parent(b);
        // If they are already in the same group, return.
        if (parent_a == parent_b) {
            return;
        }
        // Merge the smaller group into the larger group.
        if (group_size[parent_a] >= group_size[parent_b]) {
            parent[parent_b] = parent_a;
            group_size[parent_a] += group_size[parent_b];
        } else {
            parent[parent_a] = parent_b;
            group_size[parent_b] += group_size[parent_a];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        // Initialize the parent vector and the group size vector.
        parent.resize(n);
        group_size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        // Merge the nodes in the edges.
        for (auto& edge : edges) {
            merge(edge[0], edge[1]);
        }
        // Calculate the total number of pairs.
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                ans += 1LL * (n - group_size[i]) * group_size[i];
            }
        }
        // Divide the total number of pairs by 2, since each pair is counted twice.
        return ans / 2;
    }
};