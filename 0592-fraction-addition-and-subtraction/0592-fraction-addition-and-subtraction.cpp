class Solution {
public:
    string fractionAddition(string exp) {
        int num = 0;
        int deno = 1;
        int i = 0;
        int n = exp.length();
        while (i < n) {
            int cnum = 0;
            int cdeno = 0;
            bool isNeg = (exp[i] == '-');
            if (exp[i] == '+' || exp[i] == '-') {
                i++;
            }
            while(i<n && isdigit(exp[i])){
                int val = exp[i]-'0';
                cnum = cnum*10 + val;
                i++;
            }
            i++;
            if(isNeg == true){
                cnum *= -1;
            }
            while(i<n && isdigit(exp[i])){
                int val = exp[i]-'0';
                cdeno = (cdeno*10) + val;
                i++;

            }
            num = num*cdeno + cnum*deno;
            deno = deno*cdeno;
        }

        int GCD = abs(__gcd(num , deno));
        num /= GCD;
        deno /= GCD;
        return to_string(num) + "/"+to_string(deno);
    }
};