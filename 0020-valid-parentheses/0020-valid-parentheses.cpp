class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closedOpenBracketsMap = 
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> charStack;

        for(char &ch : s)
        {
            if(closedOpenBracketsMap.count(ch))
            {
                if(charStack.empty() or closedOpenBracketsMap[ch] != charStack.top())
                    return false;
                charStack.pop();
            }
            else
                charStack.push(ch);
        }
        return charStack.empty();   
    }
};