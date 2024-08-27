class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> result(n,0);
        unordered_map<int , vector<pair<int,double>>> adj; //adj list to store node and its reachable nodes along with their probabilities
        for(int i = 0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
    
        priority_queue<pair<double,int>> pq;      //heap will have pair of {prob,node}
        pq.push({1.0,start_node});              //pushing the starting node along with its prob
        result[start_node] = 1.0;      //probability of starting node to reach itself will be 1 , instead of 0 (also we are multiplying the probabilties)
        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto &temp : adj[currNode]){
                double adjProb = temp.second;
                int adjNode = temp.first;
                if(result[adjNode] < currProb*adjProb){       // if we have a greater probabily found for a path. Then we will update it
                    result[adjNode] = currProb*adjProb;
                    pq.push({result[adjNode],adjNode});       //then we will push this updated prob,node to heap , so that another maximum prob can be found.
                }
            }
        }
        return result[end_node];
    }
};