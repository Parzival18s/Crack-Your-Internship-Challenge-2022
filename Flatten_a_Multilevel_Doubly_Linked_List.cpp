class Solution {
public:
    Node* flatten(Node* head) {
        Node*ptr;
        stack<Node*>s;
        ptr=head;
        if(!(head))
            return head;
        while(s.size() or ptr->next or ptr->child)
        {
            if(ptr->next==NULL and ptr->child==NULL)
            {
                Node*p;
                p=s.top();
                ptr->next=p;
                p->prev=ptr;
                s.pop();
            }
            else
            {
                if(ptr->child)
                {
                    if(ptr->next)
                    {
                        s.push(ptr->next);
                        ptr->next=ptr->child;
                        ptr->child->prev=ptr;
                        ptr->child=NULL;
                    }
                    else
                    {
                        ptr->next=ptr->child;
                        ptr->child->prev=ptr;
                        ptr->child=NULL;
                    }
                }
            }
            ptr=ptr->next;
        }
        return head;
    }
};