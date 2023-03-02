class Solution {
public:
    int compress(vector<char>& chars) {

    if(chars.size() == 1)
        {
            return 1;
        }


        int returnValIndex = 0;
        char currentChar = chars[0];
        int i = 0;

        while(i < chars.size())
        {
            int newCharStartIndex = i;
            while(i < chars.size() && chars[i] == currentChar)
            {
                ++i;
            }

            chars[returnValIndex++] = currentChar;

            if(i - newCharStartIndex > 1)
            {
                std::string numStr = std::to_string(i - newCharStartIndex);
                for(const auto& num : numStr)
                {
                    chars[returnValIndex++] = num;
                }
            }

            if(i < chars.size())
            {
                currentChar = chars[i];
            }
        }

        //Problem specifies to return the length of the new array. Assuming we iterate
        //through the loop at all, currentCharIndex should be at the location of the >next<
        //character to replace which should be the same as the length.
        return returnValIndex;
        
    }
};