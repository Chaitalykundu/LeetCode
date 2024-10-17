class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        priority_queue<pair<char,int>> pq;

        for(int i=0;i<s.size();i++){
            pq.push({s[i],i});
        }

        for(int j=0;j<s.size();j++){
            while(!pq.empty() && pq.top().second<j) pq.pop();
            if(pq.top().first > s[j]){
                swap(s[j],s[pq.top().second]);
                break;
            }
        }

        return stoi(s);
    }
};