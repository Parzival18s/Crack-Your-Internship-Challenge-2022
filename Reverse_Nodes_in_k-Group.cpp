class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr=head;
        vector<ListNode*>vec;
        while(ptr)
        {
            vec.push_back(ptr);
            ptr=ptr->next;
        }
        int cnt=vec.size()/k;
        bool change=true;
        int i=0,j;
        for(int p=0;p<cnt;p++)
        {
            j=i+1;
            while(j<i+k)
            {
                vec[j]->next=vec[j-1];
                j++;
            }
            if(p<cnt-1)
            {
                j--;
                j+=k;
                vec[i]->next=vec[j];
            }
            else
            {
                if(j<vec.size())
                    vec[i]->next=vec[j];
                else
                    vec[i]->next=NULL;
            }
            i+=k;
            if(change)
            {
                head=vec[i-1];
                change=false;
            }
        }
        return head;
    }
};