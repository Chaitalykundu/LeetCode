#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q[2];//q[0] for positive, q[1] negaitive
        int idx=0;
        for(int x: nums){
            q[x<0].push(x);//Push negative numbers into q[1], positive numbers into q[0]
            // While the queue at current index has some, pop them and assign to nums array
            while (!q[idx&1].empty()){
                nums[idx]=q[idx&1].front();
                q[idx&1].pop();
                idx++;// Move to the next index
            }
        }
        return move(nums);       
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();