class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_map<int,int> a;
        for(auto i:nums)
        a[i]++;
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while(head)
        {
            int val = head->val;
            head = head->next;
            if(a[val]!=1)
            {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }
        a.empty();
        return ans->next;


    }
};