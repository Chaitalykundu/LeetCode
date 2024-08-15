class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        vector<int> freq(3,0);
        int ans=true;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                freq[0]++;
            }
            else if(bills[i]==10){
                freq[1]++;
                if(freq[0]!=0){
                    freq[0]--;
                }
                else{
                    ans=false;
                    break;
                }
            }
            else if(bills[i]==20){
                freq[2]++;
                if((freq[0]!=0) && (freq[1]!=0)){
                    freq[0]--;
                    freq[1]--;
                }
                else if(freq[0]>=3){
                    freq[0]-=3;
                }
                else{
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
};