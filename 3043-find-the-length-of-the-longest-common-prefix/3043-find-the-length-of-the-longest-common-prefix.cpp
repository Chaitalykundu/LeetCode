class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        unordered_set<string> prefixes; //used unordered set to avoid copies and save a bit of memory
        for(auto it:arr1)
        {
            string temp= to_string(it); //converted to string for easy prefix extraction
            for(int i=1;i<=temp.length();i++)
                prefixes.insert(temp.substr(0,i));
        }
        int ans=0;
        for(auto it:arr2)
        {
            string temp= to_string(it);
            for(int i=1;i<=temp.length();i++)
            {
                string t= temp.substr(0,i);
                if(prefixes.find(t)!=prefixes.end()) //instead of creating another hashset, i basically searched for it as it will be constant time operation and will save memory
                    ans = ans>t.length()?ans:t.length(); //ternary operator >>> max (dk but my personal fav)
            }
        }
        // for(auto it:prefixes)
        //     cout<<it<<endl;
        return ans;
    }
};