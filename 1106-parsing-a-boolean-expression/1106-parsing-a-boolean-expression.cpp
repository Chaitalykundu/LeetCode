class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> charStack;
        vector<bool> boolResults;
        bool currentResult;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ')') {
                // Clear the temporary boolean result list
                boolResults.clear();
                
                // Process the characters inside parentheses
                while (!charStack.empty()) {
                    char currentChar = charStack.top();
                    charStack.pop();

                    if (currentChar == 't') {
                        boolResults.push_back(true);
                    }
                    if (currentChar == 'f') {
                        boolResults.push_back(false);
                    }

                    if (currentChar == '|') {
                        // OR operation
                        currentResult = false;
                        for (bool val : boolResults) {
                            if (val) {
                                currentResult = true;
                                break;
                            }
                        }
                        boolResults.clear();
                        break;
                    }

                    if (currentChar == '&') {
                        // AND operation
                        currentResult = true;
                        for (bool val : boolResults) {
                            if (!val) {
                                currentResult = false;
                                break;
                            }
                        }
                        boolResults.clear();
                        break;
                    }

                    if (currentChar == '!') {
                        // NOT operation
                        currentResult = !boolResults[0];
                        boolResults.clear();
                        break;
                    }
                }
                
                if (currentResult) {
                    charStack.push('t');
                } else {
                    charStack.push('f');
                }
            }
            else {
                charStack.push(expression[i]);
            }
        }

        return currentResult;
    }
};

