class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int>cnt;
        for(auto it:s) cnt[it]++;
        if(cnt['a'] < k || cnt['b'] < k  || cnt['c'] < k ) return -1;

        int windowSize = 0, startPos = 0;
        int n = s.size();
        int ans = s.size();
        // try to find the max window as possible
        // max window size = min leftover(what the problem asks for)
        for(int i=0; i<n; i++){
            windowSize++;
            cnt[s[i]]--;

            while(cnt[s[i]] < k){
                cnt[s[startPos]]++;
                startPos++;
                windowSize--;
            }
            // Why can we constantly move the window to the right (incrementing j)
            // if it dose not meet the criteria for the first time?
            // answer:
            //      If left startPos char out for the first time will cause the answer invalid, 
            //      no matter how big the window is, it will never be a valid answer.
            //      If n-1 is valid, we know the window size n-1 is valid and there is no need for testing a smaller window size.
            ans = min(ans, n- windowSize);
        }
        return ans;
    }
};