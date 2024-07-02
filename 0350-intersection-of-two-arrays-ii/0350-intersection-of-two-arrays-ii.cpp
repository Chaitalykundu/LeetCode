class Solution {
public: 
//BASIC BINARY SEARCH BUT WITH UPDATED METHOD FOR THE VISITED ELEMENT OR FOR VISITED INDEX
bool chk_presence(vector<int>& arr, int num, set<int>& used) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num) {
            // Ensure this element is not already used
            if (used.find(mid) == used.end()) {
                used.insert(mid);
                return true;
            } 
            else {
                // Element is found but already used, continue search
                int l = mid - 1;
                int r = mid + 1;
                while (l >= low || r <= high) {
                    if (l >= low && arr[l] == num && used.find(l) == used.end()) {
                        used.insert(l);
                        return true;
                    }
                    if (r <= high && arr[r] == num && used.find(r) == used.end()) {
                        used.insert(r);
                        return true;
                    }
                    l--;
                    r++;
                }
                return false;
            }
        } 
        else if (arr[mid] > num) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return false;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ans;

    // Sort both arrays
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // Set to track used elements
    set<int> used;

    // Iterate over the smaller array and perform binary search on the larger array
    if (n1 <= n2) {
        for (int num : nums1) {
            if (chk_presence(nums2, num, used)) {
                ans.push_back(num);
            }
        }
    } else {
        for (int num : nums2) {
            if (chk_presence(nums1, num, used)) {
                ans.push_back(num);
            }
        }
    }

    return ans;
}

};