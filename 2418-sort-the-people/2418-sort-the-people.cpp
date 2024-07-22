class Solution {
public:
void insertionSort(vector<int>&arr,vector<string>&heights, int n)
{
    int i, key, j;
    string str;
    for (i = 1; i < n; i++) {
        key = arr[i];
        str = heights[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            heights[j+1] = heights[j];
            j = j - 1;
        }
        heights[j+1] = str;
        arr[j + 1] = key;
    }
}
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        insertionSort(heights,names,heights.size());
        reverse(names.begin(),names.end());
        return names;
    }
};