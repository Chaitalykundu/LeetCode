class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>st,en;
        for(auto it:intervals){
            st.push_back(it[0]);
            en.push_back(it[1]);
        } 
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        int groups=0,end=0;
        for(auto s:st){
            if(s>en[end]){
                end++;
            }
            else
            groups++;
        }
        return groups;
    }
};