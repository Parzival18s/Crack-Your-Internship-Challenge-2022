class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr;
        ptr=head;
        int len=0;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }
        ptr=head;
        for(int i=0;i<len/2;i++)
            ptr=ptr->next;
        return ptr;
    }
};