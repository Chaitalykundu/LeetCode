class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        // for storing frequencies of both strings and comparing
        vector<int> s1count(26, 0), s2count(26, 0);
        for (int i = 0; i < n1; i++) {
            // storing initials of both strings
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }
        // now comparing how many are same characters
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1count[i] == s2count[i]) matches++;
        }
        // now moving our window ahead
        for (int i = n1; i < n2; i++) {
            // if all are equal in both frequencies array i.e. all matched
            if (matches == 26) return true;
            // now considering current one and checking if its same as in s1 or not
            int curr = s2[i] - 'a';
            // for example - a:2 in s2, a:3 in s1
            s2count[curr]++;
            // after this a:3 in s2 too
            if (s2count[curr] == s1count[curr]) matches++; // so matches will increment
            // but there can be a case if a is already 3 in s2 then after adding it will be
            // as a:4 in s2 and a:3 in s1 so mismatch so decrement matches
            else if (s2count[curr] == s1count[curr] + 1) matches--;
            // now after considering current element in window need to check first element
            // to remove or not in window
            int prev = s2[i - n1] - 'a';
            s2count[prev]--;
            // same cases as curr element 
            // if after decrementing its same as s1 so increase matches
            if (s2count[prev] == s1count[prev]) matches++;
            // otherwise if it was equal earlier but not now so decrement matches
            else if (s2count[prev] == s1count[prev] - 1) matches--;
        }
        // now at last check if all matched or not
        return matches == 26;
    }
};