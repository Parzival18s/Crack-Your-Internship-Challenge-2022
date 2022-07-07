class Solution{
    public:
    bool helper(Node* root,int ptr)
    {
        if(root==NULL)
            return false;
        queue<Node*>q;
        q.push(root);
        while(!(q.empty()))
        {
            if(q.front()->data==ptr)
                return true;
            if(q.front()->right)
                q.push(q.front()->right);
            if(q.front()->left)
                q.push(q.front()->left);
            q.pop();
        }
        return false;
    }
    int help(Node* root,int ptr)
    {
        if(root->data==ptr)
            return 0;
        if(helper(root->left,ptr))
            return 1+help(root->left,ptr);
        return 1+help(root->right,ptr);
    }
    int findDist(Node* root, int a, int b) {
        if(root->data==a)
            return help(root,b);
        if(root->data==b)
            return help(root,a);
        bool p,q;
        p=helper(root->right,a);
        q=helper(root->left,b);
        if((p and q) or (!p and !q))
            return help(root,a)+help(root,b);
        if(p)
            return findDist(root->right,a,b);
        return findDist(root->left,a,b);
    }
};
