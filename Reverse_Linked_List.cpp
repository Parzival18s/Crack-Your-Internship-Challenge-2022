class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!(head))
            return head;
        if(!(head->next))
            return head;
        
        ListNode *a,*b,*c;
        a=NULL;
        b=head;
        c=head->next;
        
        while(c)
        {
            b->next=a;
            a=b;
            b=c;
            c=c->next;
        }
        b->next=a;
        return b;
    }
};