//Without Reversing the lists
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>a,b;
        int tmp=0,carry=0;
        ListNode* ptr1,* ptr2;
        ptr1=new ListNode();
        while(l1)
        {
            a.push(l1);
            l1=l1->next;
        }
        while(l2)
        {
            b.push(l2);
            l2=l2->next;
        }
        while((!(a.empty())) or (!(b.empty())) or carry)
        {
            if(!(a.empty()))
            {
                tmp+=a.top()->val;
                a.pop();
            }
            if(!(b.empty()))
            {
                tmp+=b.top()->val;
                b.pop();
            }
            tmp+=carry;
            ptr1->val=tmp%10;
            carry=tmp/10;
            tmp=0;
            if(!((!(a.empty())) or (!(b.empty())) or carry))
                return ptr1;
            ptr2=new ListNode();
            ptr2->next=ptr1;
            ptr1=ptr2;
        }
        return ptr1;
    }
};