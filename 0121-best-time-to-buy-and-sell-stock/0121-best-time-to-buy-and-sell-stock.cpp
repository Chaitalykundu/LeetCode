class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    int minPricePos = 0,maxProfit = 0;
    for(int i = 1;i<prices.size();i++)
    {    
        if(prices[i] - prices[minPricePos] > maxProfit)
            maxProfit = prices[i] - prices[minPricePos] ;
        else if(prices[i] - prices[minPricePos] < 0)
            minPricePos = i;
    }
    return maxProfit;
    }
};