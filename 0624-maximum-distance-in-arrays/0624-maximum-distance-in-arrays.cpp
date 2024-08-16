class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first; 
    }
    
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        vector<pair<int,int>>vec;
        pair<int,int>p;

        for(int i = 0; i < arrays.size(); i++){
            int size = arrays[i].size();
            if(size == 1){
                vec.push_back({arrays[i][0], i});
            }
            else{
                vec.push_back({arrays[i][0], i});
                vec.push_back({arrays[i][size - 1], i});
            }
        }
        sort(vec.begin(),vec.end(),compare);

        pair<int,int>maxi = vec[vec.size() - 1];
        pair<int,int>mini = vec[0];
        
        if(maxi.second == mini.second){
            mini = vec[1];
            int diff1 = abs(maxi.first - mini.first);

            mini = vec[0];
            maxi = vec[vec.size() - 1 - 1];
            int diff2 = abs(maxi.first - mini.first);

            return max(diff1,diff2);
        }

        return abs(maxi.first - mini.first);
    }
};