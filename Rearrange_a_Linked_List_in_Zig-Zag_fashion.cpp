class Solution{
public:
    void zigZagList(Node* head)
    {
        int flag=1;
        Node* ptr=head;
        while(ptr->next)
        {
            if (flag%2)
            {
                if(ptr->data>ptr->next->data)
                    swap(ptr->data,ptr->next->data);
            }
            else
            {
                if(ptr->data<ptr->next->data)
                    swap(ptr->data,ptr->next->data);
            }
            ptr=ptr->next;
            flag++;
            flag%=2;
        }
        return;
    }
};