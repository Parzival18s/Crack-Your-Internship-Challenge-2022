class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *ptr;
        ptr=head;
        int len=0;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }
        int ans=0;
        len--;
        while(head)
        {
            if(head->val==1)
                ans+=pow(2,len);
            head=head->next;
            len--;
        }
        return ans;
    }
};