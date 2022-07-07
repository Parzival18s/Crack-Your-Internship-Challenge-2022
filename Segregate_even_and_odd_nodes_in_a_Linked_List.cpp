class Solution{
public:
    ListNode* segregateEvenOdd(ListNode* head)
    {
        ListNode* ptr=head;
        queue<int>even,odd;
        while(ptr)
        {
            if(ptr->val%2)
                odd.push(ptr->val);
            else
                even.push(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr)
        {
            if(even.size()>0)
            {
                ptr->val=even.front();
                even.pop();
            }
            else
            {
                ptr->val=odd.front();
                odd.pop();
            }
            ptr=ptr->next;
        }
        return head;
    }
};