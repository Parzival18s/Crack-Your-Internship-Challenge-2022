class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if((!(head)) or (!(head->next)))
            return head;
        while( head and head->next and head->val==head->next->val)
        {
            while((head) and (head->next) and (head->val==head->next->val))
                head=head->next;
            if(head)
                head=head->next;
        }
        if((!(head)) or (!(head->next)))
            return head;
        ListNode* p1,* p2,* p3;
        p1=head;
        p2=p1->next;
        if(p2->next==NULL)
            return head;
        p3=p2->next;
        while(p3)
        {
            if(p2->val!=p3->val)
            {
                p1=p1->next;
                p2=p2->next;
                p3=p3->next;
            }
            else
            {
                p3=p2->next;
                while(p3 and p3->val==p2->val)
                    p3=p3->next;
                p1->next=p3;
                p2=p3;
                if(p3)
                    p3=p3->next;
            }
        }
        return head;
    }
};