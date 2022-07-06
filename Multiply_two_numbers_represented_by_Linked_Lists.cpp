class Solution{
public:
    int multiplyLinkedLists(Node* head1,Node* head2)
    {
        int a=0,b=0;
        while(head1)
        {
            a*=10;
            a+=head1->data;
            head1=head1->next;
        }
        while(head2)
        {
            b*=10;
            b+=head2->data;
            head2=head2->next;
        }
        return a*b;
    }
};