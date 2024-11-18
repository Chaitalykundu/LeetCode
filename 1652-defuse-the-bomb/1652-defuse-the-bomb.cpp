class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> pref(n,0);
        if(k==0)return pref;
        pref[0]=code[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[(i-1)%n]+code[i];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(k>0){
                int start=(i+1)%n,end=(i+k)%n;
                if(start>end){
                    ans[i]=code[start]+(pref[n-1]-pref[start])+pref[end];
                }else{
                    ans[i]=pref[end]-pref[start]+code[start];
                }
            }else if(k<0){
                int start=(i-1<0)?n-i-1:i-1,end=(i+k<0)?n-abs(i+k):i+k;
                if(start<end){
                    ans[i]=code[end]+(pref[n-1]-pref[end])+pref[start];
                }else ans[i]=pref[start]-pref[end]+code[end];
            }
        }
        return ans;
    }
};