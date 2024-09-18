class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [](int a, int b){
            string str1 = to_string(a);
            string str2 = to_string(b);
            return str1+str2 > str2+str1;
        };

        int n = nums.size();
        if(count(nums.begin(),nums.end(),0) == n){
            return "0";
        }

        sort(nums.begin(),nums.end(),comp);
        string str ="";
        for(auto i=0;i<nums.size();i++){
            str= str+to_string(nums[i]);
        }
        return str;

    }
};