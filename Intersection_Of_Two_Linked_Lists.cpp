class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *ptr1,*ptr2;
        
        ptr1=headA;
        while(ptr1)
        {
            l1++;
            ptr1=ptr1->next;
        }
        
        ptr2=headB;
        while(ptr2)
        {
            l2++;
            ptr2=ptr2->next;
        }
        
        ptr1=headA;
        ptr2=headB;
        
        
        if(l1>l2)
        {
            for(int i=0;i<l1-l2;i++)
                ptr1=ptr1->next;
        }
        else if(l2>l1)
        {
            for(int i=0;i<l2-l1;i++)
                ptr2=ptr2->next;
        }
        while(ptr1 and ptr2)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return NULL;
    }
};