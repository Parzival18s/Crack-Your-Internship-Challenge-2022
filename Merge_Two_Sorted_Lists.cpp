class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head,*ptr,*tmp;
        head=new ListNode;
        ptr=head;
        while(list1 and list2)
        {
            if(list1->val<list2->val)
            {
                tmp=new ListNode(list1->val);
                ptr->next=tmp;
                ptr=ptr->next;
                list1=list1->next;
            }
            else
            {
                tmp=new ListNode(list2->val);
                ptr->next=tmp;
                ptr=ptr->next;
                list2=list2->next;
            }
        }
        if(list1)
        {
            ptr->next=list1;
        }
        if(list2)
        {
            ptr->next=list2;
        }
        return head->next;
    }
};