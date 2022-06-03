class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!(head))
            return head;
        while(head and head->val==val)
            head=head->next;
        if(!(head))
            return head;
        
        if(!(head->next))
            return head;
        
        
        ListNode *ptr1,*ptr2;
        
        ptr1=head;
        ptr2=head->next;
        while(1)
        {
            if(ptr2->val!=val)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else
            {
                while(ptr2 and ptr2->val==val)
                    ptr2=ptr2->next;
                ptr1->next=ptr2;
            }
            if(!(ptr2))
                break;
        }
        return head;
    }
};