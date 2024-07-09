class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        double totalWaitTime = 0;
        int currentTime = customers[0][0];
        for(auto customer : customers) {
            if(currentTime < customer[0])
                currentTime = customer[0];
            currentTime += customer[1];
            totalWaitTime += (currentTime - customer[0]);
        }
        return totalWaitTime / customers.size();
    }
};