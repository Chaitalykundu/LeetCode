class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long long res = 0;
        priority_queue<int> pq;
        for(int i : nums){
            pq.push(i);
        }
        while(!pq.empty() && k){
            int num = pq.top();
            pq.pop();
            res += num;
            int newNum = (num+2) / 3;
            if(newNum) pq.push(newNum);
            k--;
        }
        return res;
    }
};