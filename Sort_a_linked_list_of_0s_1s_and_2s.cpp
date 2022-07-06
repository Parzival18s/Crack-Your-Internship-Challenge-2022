class Solution{
public:
    void sortList(Node* head)
    {
        Node* ptr=head;
        int o=0,z=0;
        while(ptr)
        {
            if(ptr->data==0)
                z++;
            else if(ptr->data==1)
                o++;
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr)
        {
            if(z>0)
            {
                ptr->data=0;
                z--;
            }
            else if(o>0)
            {
                ptr->data=1;
                o--;
            }
            else
                ptr->data=2;
            ptr=ptr->next;
        }
        return;
    }
};