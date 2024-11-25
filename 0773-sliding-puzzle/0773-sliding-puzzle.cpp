class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string st = ""; 
        // Convert the 2D board into a single string representation for easier manipulation.
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                st += to_string(board[i][j]); 
                // Append each element of the board to the string.
            }
        }

        unordered_set<string> visited; 
        // A set to keep track of visited states to avoid reprocessing them.
        visited.insert(st); // Mark the initial state as visited.

        unordered_map<int, vector<int>> adj; 
        // Define the adjacency list representing the possible moves for each index.
        adj[0] = {1, 3}; 
        adj[1] = {0, 2, 4};
        adj[2] = {1, 5};
        adj[3] = {0, 4};
        adj[4] = {1, 3, 5};
        adj[5] = {2, 4};

        queue<string> q; 
        // A queue for BFS traversal. Each string represents a state of the puzzle.
        q.push(st); 

        string res = "123450"; 
        // The target string representing the solved state of the puzzle.

        int level = 0; 
        // BFS level (or number of moves).

        while (!q.empty()) { 
            // BFS loop until the queue is empty.
            int n = q.size(); 
            // Number of states at the current level.

            for (int i = 0; i < n; i++) {
                string curr = q.front(); 
                q.pop(); // Get the current state from the queue.

                if (curr == res) { 
                    // If the current state matches the target, return the number of moves.
                    return level;
                }

                int zeroIndex = curr.find('0'); 
                // Find the index of '0' (empty space) in the current state.

                for (auto swapIndex : adj[zeroIndex]) { 
                    // Explore all possible positions to swap with '0'.
                    string temp = curr; 
                    swap(temp[swapIndex], temp[zeroIndex]); 
                    // Swap '0' with the element at the adjacent position.

                    if (visited.find(temp) == visited.end()) { 
                        // If the new state has not been visited:
                        visited.insert(temp); 
                        // Mark it as visited.
                        q.push(temp); 
                        // Add the new state to the queue for further exploration.
                    }
                }
            }
            level++; 
            // Increment the number of moves after exploring all states at the current level.
        }

        return -1; 
        // If the target state is not reachable, return -1.
    }
};
