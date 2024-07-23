class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto &b: nums){mp[b]++;}
        vector<pair<int, int>>p;
        for(auto &b: mp){
            p.push_back({b.second, b.first});
        }
        sort(p.begin(), p.end(), [](pair<int, int>aa, pair<int, int>bb){
            if(aa.first==bb.first){return aa.second>bb.second;}
            return aa.first<bb.first;
        });
        vector<int>ans;
        for(auto &b: p){
            int xx=b.first, yy=b.second;
            while(xx--){ans.push_back(yy);}
        }
        return ans;
    }
};