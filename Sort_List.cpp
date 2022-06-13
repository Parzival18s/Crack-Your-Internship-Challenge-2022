class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* ptr;
        ptr=head;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(v.begin(),v.end());
        ptr=head;
        for(int i=0;i<v.size();i++)
        {
            ptr->val=v[i];
            ptr=ptr->next;
        }
        return head;
    }
};