class Solution {
public:
    // Function to find the minimum number of buses needed to reach the target from the source.
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        // If source and target are the same, no buses are needed.
        if (source == target) {
            return 0;
        }

        // Create an adjacency list to represent stops and the routes that include each stop.
        std::unordered_map<int, std::vector<int>> adjList;
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adjList[stop].push_back(route);
            }
        }

        // Initialize a queue for BFS and a set to keep track of visited routes.
        std::queue<int> q;
        std::unordered_set<int> vis;

        // Insert all the routes in the queue that have the source stop.
        for (auto route : adjList[source]) {
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1; // Initialize the bus count.

        // Perform BFS to find the minimum number of buses needed.
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();

                // Iterate over the stops in the current route.
                for (auto stop : routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current stop.
                    for (auto nextRoute : adjList[stop]) {
                        if (!vis.count(nextRoute)) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }

        // If no route is found, return -1.
        return -1;
    }
};

