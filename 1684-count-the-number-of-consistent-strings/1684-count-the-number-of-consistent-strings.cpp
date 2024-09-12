class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool>mp;
        for(auto i: allowed){
            mp[i] = true;
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(mp[words[i][j]]!=true){
                    break;
                }
                if(j==words[i].size()-1 && mp[words[i][j]]){
                    count++;
                }
            }
        }
        return count;
    }
};