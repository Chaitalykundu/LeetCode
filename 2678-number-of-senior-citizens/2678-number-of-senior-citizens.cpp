class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        int n = details[0].size();
        for(string str:details){
            
            int num = 10*(str[n-4] - '0') + (str[n-3] - '0');
            if(num > 60){
                cnt++;
            }
        }
        return cnt;
    }
};