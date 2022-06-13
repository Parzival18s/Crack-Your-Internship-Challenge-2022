class Solution {
public:
    void helper(ListNode* head)
    {
        if(!(head))
            return;
        if(head->next==NULL)
            return;
        ListNode* p1,* p2,* p3;
        p1=head;
        p2=head->next;
        p1->next=NULL;
        if(p2->next==NULL)
        {
            p2->next=p1;
            return;
        }
        p3=p2->next;
        while(p3)
        {
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p3->next;
        }
        p2->next=p1;
        return;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p1,* p2,* p3,* p4;
        p2=head;
        for(int i=0;i<left-1;i++)
        {
            p1=p2;
            p2=p2->next;
        }
        p3=head;
        for(int i=0;i<right-1;i++)
            p3=p3->next;
        p4=p3->next;
        p3->next=NULL;
        helper(p2);
        if(left==1)
        {
            p2->next=p4;
            return p3;
        }
        p1->next=p3;
        p2->next=p4;
        return head;
    }
};