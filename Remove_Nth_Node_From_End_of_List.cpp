class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr,* ptr1;
        ptr=head;
        int len=0;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }
        int pos=len-n+1;
        if(pos==1)
        {
            ptr=head;
            head=head->next;
            ptr->next=NULL;
            return head;
        }
        ptr=head;
        for(int i=1;i<pos-1;i++)
            ptr=ptr->next;
        ptr1=ptr->next;
        ptr1=ptr1->next;
        ptr->next=ptr1;
        return head;
    }
};