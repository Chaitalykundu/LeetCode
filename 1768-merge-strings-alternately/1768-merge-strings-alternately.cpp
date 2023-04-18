class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string s;
        
        int i=0;
        for(i=0;i<m && i<n;i++)
        {
            s.push_back(word1[i]);
            s.push_back(word2[i]);
        }
        
        if(i==word1.size()){
            for(int j = i;j<word2.size();j++) s.push_back(word2[j]);
        }
        else if(i==word2.size()){
            for(int j = i;j<word1.size();j++) s.push_back(word1[j]);
        }
        return s;
        
    }
};