class Solution {
public:
    string nearestPalindromic(string n) {
        int l=n.size();
        set<long>canBeNumber;
        // biggest , one more more digit eg. 999 to 1001(as 1001 is a palindrome)
        canBeNumber.insert(long(pow(10,l))+1);
        /// smallest one less digit , like 1000 nearest 999 is palindrome 
        canBeNumber.insert(long(pow(10,l-1)-1)); 

        // last pattern will be mid digit of the number is +1, 0,-1 -> 99800 -> 99799 like this,

        long long prefix=stol(n.substr(0,(l+1)/2));// take first half of the string with mid digit as long
        for(int i=-1;i<=1;i++){
            string p=to_string(prefix+i);// -1 0 1 to integer
            string pp=p+string(p.rbegin()+(l & 1), p.rend());// take the left/ start string without mid digit in reverse order
            canBeNumber.insert(stol(pp));
        }

        //  final operation check the closet
        long num=stol(n) ;
        long minDiff= LONG_MAX;
        long  ans;
        for(long val : canBeNumber){
            if(val==num){// as 999 we are taking and for 999 we want accept that any plaidrome
                continue;
            }
            if(minDiff>abs(val-num)){
                ans=val;
                minDiff=abs(val-num);
            }
            else if(minDiff==abs(val-num)){
                ans=min(ans,val);
            }
        }
        return to_string(ans);
    }
};