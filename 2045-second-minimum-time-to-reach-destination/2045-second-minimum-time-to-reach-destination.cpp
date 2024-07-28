class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n+1);

        for(auto& curr: edges){
            int a = curr[0];
            int b = curr[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        vector<pair<int, int>> distances(n+1, {INT_MAX, INT_MAX});
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        distances[1] = {0, 0};
        pq.push({0, 1});

        while(pq.size() > 0){
            pair<int, int> top = pq.top(); pq.pop();
            int dist = top.first;
            int node = top.second;
            int c = dist/change;
            int r = change-(dist%change);
            if(c%2 != 0) dist += r;
            vector<int> children = adjList[node];

            for(auto& child: children){
                int newDist = dist+time;
                if(newDist < distances[child].first){
                    distances[child].second = distances[child].first;
                    distances[child].first = newDist;
                    pq.push({newDist, child});
                } else if(newDist < distances[child].second && newDist != distances[child].first){
                    distances[child].second = newDist;
                    pq.push({newDist, child});
                }
            }
        }

        if(distances[n].second == INT_MAX){
            // we need to go back to any adjacenet node and come back again.
            int dist = distances[n].first;
            int c = dist/change;
            int r = change-(dist%change);
            if(c%2 != 0) dist += r;

            int newDist = dist+time;
            c = newDist/change;
            r = change-(newDist%change);
            if(c%2 != 0) newDist += r;

            return newDist+time;
        }

        return distances[n].second;
    }
private:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        }
    };
};

/*
    go from 1 to n

    odd are red
    even are green

    minimum time to go from 1 to n

    minimum distance from 1 to n using djistra algorithm and taking the time
    as weights

    but how do we get the second minimum distance

    for the djistra we keep track of two distances instead of one

    min1 and min2
*/