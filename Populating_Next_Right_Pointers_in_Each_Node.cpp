class Solution {
public:
    Node* connect(Node* root) {
        if(!(root))
            return root;
        queue<Node*>q;
        q.push(root);
        Node* ptr;
        while(!(q.empty()))
        {
            int tmp=q.size();
            ptr=q.front();
            q.pop();
            for(int i=1;i<tmp;i++)
            {
                ptr->next=q.front();
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
                ptr=q.front();
                q.pop();
            }
            ptr->next=NULL;
            if(ptr->left)
                q.push(ptr->left);
            if(ptr->right)
                q.push(ptr->right);
        }
        return root;
    }
};