void helper_suc(Node* root, Node* &succ, int key)
{
    while(root!=NULL)
    {
        if(root->key<=key)
        {
            root=root->right;
        }
        else if(root->key>key)
        {
            succ=root;
            root=root->left;
        }
    }
}

void helper_pre(Node* root, Node* &pred, int key)
{
    while(root!=NULL)
    {
      
        if(root->key>=key)
        {
            root=root->left;
        }
        else if(root->key<key)
        {
            pred=root;
            root=root->right;
        }
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    helper_suc(root,suc,key);
    helper_pre(root,pre,key);
    return;
}