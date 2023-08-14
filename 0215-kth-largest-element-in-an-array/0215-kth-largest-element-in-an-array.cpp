class Solution {
public:
    void print( multiset<int>& mset){
        for(auto it=mset.begin(); it!=mset.end(); it++)
            cout<<*it<<",";
        cout<<endl;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> mset(nums.begin(), nums.begin()+k);
    //    print(mset);
        multiset<int>::iterator it;
        for (int i=k; i<n; i++){
            mset.insert(nums[i]);
            it=mset.begin();
            mset.erase(it);
        }
    //    print(mset);
        return *mset.begin();
    }
};