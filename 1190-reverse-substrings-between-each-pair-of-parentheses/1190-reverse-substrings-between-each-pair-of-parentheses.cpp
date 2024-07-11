class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesis;
        int size = s.size();
        for(int i=0; i<size; i++)
        {
            if(s[i]=='(')
                openParenthesis.push(i);
            else if(s[i]==')')
            {
                int start = openParenthesis.top();  openParenthesis.pop();
                reverse(s.begin()+start+1, s.begin()+ i);
                s.erase(s.begin() + i);
                s.erase(s.begin() + start);
                i-=2;
                size-=2;
            }
        }
        return s;
    }
};
