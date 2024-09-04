class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        vector<pair<int,int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};  // N, E, S, W
        int face = 0;
        int curr_x=0;
        int curr_y=0;
        int dist=0;
        set<pair<int,int>> st;
        for(auto& o:obstacles){
            st.insert({o[0], o[1]});
        }
        for(int i=0; i<n; i++){
            int currCmd = commands[i];
            if(currCmd == -1){
                face = (face+1)%4;
            }
            else if(currCmd == -2){
                face = (face+3)%4;
            }
            else{
                for(int c=1; c<=currCmd; c++){
                    int next_x = curr_x+dir[face].first;
                    int next_y = curr_y+dir[face].second;
                    if(st.find({next_x,next_y}) != st.end()){
                        break;
                    }
                    curr_x=next_x;
                    curr_y=next_y;
                    dist = max(dist, (curr_x*curr_x) + (curr_y*curr_y));
                }
            }
        }
        return dist;
    }
};