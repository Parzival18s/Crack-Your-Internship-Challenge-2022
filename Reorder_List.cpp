class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        while(head)
        {
            v.push_back(head);
            head=head->next;
        }
        int i=0,j=v.size()-1,k=1;
        while(i<=j)
        {
            if(k%2)
            {
                v[i]->next=v[j];
                k=2;
                i++;
            }
            else
            {
                v[j]->next=v[i];
                k=1;
                j--;
            }
        }
        if(k%2)
            v[i]->next=NULL;
        else
            v[j]->next=NULL;
    }
};