class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int emptybottles=0;
        while(numBottles){
            ans+=numBottles;
            emptybottles+=numBottles;
            numBottles=emptybottles/numExchange;
            emptybottles=emptybottles%numExchange;
        }
        return ans;
    }
};