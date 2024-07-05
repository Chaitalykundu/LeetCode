class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        vector<int> ans ={-1 , -1};

        int index= 1;

        if(head == NULL || head->next == NULL) return ans;
        ListNode* pre = head;
        ListNode* node = pre->next;
        ListNode* nex = node->next;

        while(nex != NULL){
            if(node->val > pre->val && node->val > nex->val){
                arr.push_back(index);
            }else if(node->val < pre->val && node->val < nex->val){
                arr.push_back(index);
            }

            index++;
            pre = node;
            node = nex;
            nex = nex->next;
        }

        if(arr.size() < 2) return ans;
        sort(arr.begin(), arr.end());
        // cout << arr[0] << " ";
        ans[1] = arr[arr.size() - 1]  - arr[0];

        int mini  = INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini  = min(arr[i] - arr[i-1], mini);
        // cout << arr[i] << " ";

        }
        ans[0] = mini;
        return ans;
        
        
    }
};