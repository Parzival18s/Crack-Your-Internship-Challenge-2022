struct helper {
    bool operator()(Node* a,Node* b)
    {
        return a->data>b->data;
    }
};


Node *flatten(Node *root)
{
    priority_queue<Node*,vector<Node*>,helper>pq;
    while(root)
    {
        pq.push(root);
        root=root->next;
    }
    Node* ans=pq.top();
    while(!pq.empty())
    {
        Node* tmp=pq.top();
        pq.pop();
        if(tmp->bottom)
            pq.push(tmp->bottom);
        tmp->next=NULL;
        if(!pq.empty())
            tmp->bottom=pq.top();
        else
            tmp->bottom=NULL;
    }
    return ans;
}