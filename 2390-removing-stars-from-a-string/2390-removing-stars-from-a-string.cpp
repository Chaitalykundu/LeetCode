class Solution {
public:
    string removeStars(string s) {
        string p="";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='*')
                p+=s[i];
            else
                p.pop_back();
        }
        return p;
    }
};