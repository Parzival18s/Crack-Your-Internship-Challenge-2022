class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0,tmp=0;
        ListNode* head,* ptr;
        head=new ListNode();
        ptr=new ListNode();
        head->next=ptr;
        while(l1 or l2 or c)
        {
            if(l1)
            {
                tmp+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                tmp+=l2->val;
                l2=l2->next;
            }
            tmp+=c;
            ptr->val=tmp%10;
            c=tmp/10;
            tmp=0;
            if(!(l1 or l2 or c))
                break;
            ListNode*ptr1;
            ptr1=new ListNode();
            ptr->next=ptr1;
            ptr=ptr->next;
        }
        return head->next;
    }
};