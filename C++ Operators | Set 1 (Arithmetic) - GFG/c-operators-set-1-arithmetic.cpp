//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> cppOperators(int A, int B) {
        // code here
        vector<int> v;
        
        v.push_back(A+B);
        v.push_back(A*B);
        
        if(A>B)
        {
            v.push_back(A-B);
            v.push_back(A/B);
        }
        else
        {
            v.push_back(B-A);
            v.push_back(B/A);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        Solution ob;
        vector<int> ans = ob.cppOperators(A, B);
        for (int u : ans) cout << u << "\n";
    }
}
// } Driver Code Ends