class Solution {
public:
    vector<string> words {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    vector<string> tens {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string helper(int num)
    {
        if(!num)
            return "";
        int hundr = num/100;
        string res;
        if(hundr > 0)
        {
            res+=words[hundr]+" Hundred ";
        }
        int rem = num%100;
        if(rem<20 && rem>0)
            res+=words[rem];
        else if(rem>0)
        {
            int ten = rem/10;
            res+=tens[ten-2]+(rem%10?" "+words[rem%10]:"");
        }
        return res;
    }
    string numberToWords(int num) {
        if(!num)
            return "Zero";
        int r1 = num%1000;
        string res = helper(r1);
        num/=1000;
        int r2 = num%1000;
        if(r2)
        {   
            string hund = helper(r2);
            while(hund.back()==' ')
                hund.pop_back();
            res = hund +" Thousand " +res;
        }
        num/=1000;
        int r3 = num%1000;
        if(r3)
        {
            string mil = helper(r3);
            while(mil.back()==' ')
                mil.pop_back();
            res = mil+" Million "+res;
        }
        num/=1000;
        int r4 = num%1000;
        if(r4)
        {
            string bil = helper(r4);
            while(bil.back()==' ')
                bil.pop_back();
            res = bil+" Billion "+res;
        }
        while(res.back()==' ')
            res.pop_back();
        return res;
    }
};