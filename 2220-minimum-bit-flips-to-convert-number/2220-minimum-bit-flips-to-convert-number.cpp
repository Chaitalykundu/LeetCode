class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int temp=start^goal;
        for(int pos=31;pos>=0;pos--){
            if(temp>>pos&1){
                cnt++;
            }
        }
        return cnt;
    }
};