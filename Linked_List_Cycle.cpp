class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!(head))
            return false;
        
        
        if(!(head->next))
            return false;
        
        ListNode *fast,*slow;
        fast=head;
        slow=head;
        fast=fast->next;
        fast=fast->next;
        if(!(fast))
            return false;
        slow=slow->next;
        while(1)
        {
            if(slow==fast)
                break;
            if(!(fast->next))
                return false;
            fast=fast->next;
            if(!(fast->next))
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};