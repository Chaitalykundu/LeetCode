class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,pair<int,int>>> v;
        int n = times.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({times[i][0], {1,i}});
            v.push_back({times[i][1], {0,i}});
        }
        sort(v.begin(),v.end());
        for(auto i: v)
        {
            cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
        }
        vector<int> chair(n,-1);
        for(auto i: v)
        {
            int time = i.first;
            int action = i.second.first;
            int user = i.second.second;
            if(action==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(chair[j]==user)
                        chair[j] = -1;
                }
            }
            else if(action==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(chair[j]==-1)
                    {    
                        chair[j] = user;
                        if(user==targetFriend)
                            return j;
                        break;
                    }
                    
                }
            }
        }
        return -1;
    }
};