class Solution {
public:
    
    int sumOfDigits(int n){
        
        int d, res=0;
        while(n>0){
            d = n%10;
            res+=d;
            n/=10;
        }
        return res;
    }
    
    int addDigits(int num) {
        
        int ans =0 ;
        if(num<=9)
            return num;
        else if(num>9)
            ans = sumOfDigits(num);
        
        return addDigits(ans);
    }
};