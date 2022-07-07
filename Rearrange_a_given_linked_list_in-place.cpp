class Solution {
public:
    void rearrange(ListNode* head) {
        ListNode* ptr=head;
        vector<ListNode*>v;
        while(pr)
        {
            v.push_back(p);
            p=p->next;
        }
        int n=v.size();
        p=head;
        for(i=0;i<n/2;i++)
        {
            if(i!=0)
            {
                p->next=v[i];
                p=p->next;
            }
            p->next=v[n-i-1];
            p=p->next;
        }
        if(n%2)
        {
            p->next=v[i];
            p=p->next;
        }
        p->next=NULL;
    }
};