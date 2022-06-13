class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int>a,b;
        ListNode* ptr;
        ptr=head;
        while(ptr)
        {
            if(ptr->val<x)
                a.push_back(ptr->val);
            else
                b.push_back(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        for(int i=0;i<a.size();i++)
        {
            ptr->val=a[i];
            ptr=ptr->next;
        }
        for(int i=0;i<b.size();i++)
        {
            ptr->val=b[i];
            ptr=ptr->next;
        }
        return head;
    }
};