class Solution {
public:
    string countOfAtoms(string s) {
        stack<pair<string, int>>st;
        map<string , int>mp;
        int n = s.size();
        for(int i= 0 ;i < n ; i++){
            if(s[i] ==')'){
                int nxt = 0 ;
                i++;
                while(i < n && s[i] >= 48 && s[i] <= 58){
                    nxt = nxt*10+(s[i]-48);
                    i++;
                }
                i--;
                if(nxt == 0)nxt = 1;
                stack<pair<string , int>>temp;
                while(!st.empty() && st.top().first != "("){
                    temp.push({st.top().first , st.top().second*nxt});
                    st.pop();
                }
                if(!st.empty() && st.top().first == "(")st.pop();
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else{
                if(s[i] >= 65 && s[i] <= 90){
                    string temp;
                    temp += s[i];
                    i++;
                    while(i < n && s[i] >= 97 && s[i] <=122){
                        temp += s[i];
                        i++;
                    }
                     int nxt = 0;
                     while(i < n &&  s[i] >= 48 && s[i] <= 58){
                        nxt = nxt*10+(s[i]-48);
                        i++;
                     }
                     if(nxt == 0)nxt =1;
                     i--;
                     st.push({temp  , nxt});
                }else {
                    string temp ;
                    temp += s[i];
                    st.push({temp , 0});
                }
            }
        }
        while(!st.empty()){
         mp[st.top().first] += st.top().second;
         st.pop();
        }
        string ans = "";
        for(auto key : mp){
            ans += key.first;
            if(key.second >1){
                ans += to_string(key.second);
            }
        }
        return ans;
    }
};