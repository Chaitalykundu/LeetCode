class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> map;
        string s3 = s1+ " "+s2;
        stringstream ss(s3);
       string word;
       vector<string> ans;

    // Retrieve each word from the string
    while (ss >> word) {
    //    cout << word << 
       map[word]++;
    }

    // while (ss >> word) {
    //     if(  map[word]>1){
    //         ans.push_back(word);
    //     }
    
    // }

     for (const auto& pair : map) {
        if (pair.second == 1) {
             ans.push_back(pair.first );
            
        }
    }
    return ans;
      
    }
};