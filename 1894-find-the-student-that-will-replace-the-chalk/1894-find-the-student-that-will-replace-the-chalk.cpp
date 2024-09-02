class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++){
            sum=(sum+chalk[i]);
        }
        k=k%sum;
        int i=0;
        while(chalk[i]<=k){
            k-=chalk[i];
            i++;
        }
        return i;
    }
};