class Solution {
public:
    int flag=0;
    TreeNode* helper_left(TreeNode*root,TreeNode*ptr)
    {
        if(!(ptr))
            return NULL;
        queue<TreeNode*>q;
        TreeNode*tmp,*ret;
        q.push(ptr);
        ret=ptr;
        while(!(q.empty()))
        {
            tmp=q.front();
            q.pop();
            if(ret->val<tmp->val)
            {
                ret=tmp;
            }
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        if(root->val<ret->val)
            return ret;
        return NULL;
    }
   TreeNode* helper_right(TreeNode*root,TreeNode*ptr)
    {
        if(!(ptr))
            return NULL;
        queue<TreeNode*>q;
        TreeNode*tmp,*ret;
        q.push(ptr);
        ret=ptr;
        while(!(q.empty()))
        {
            tmp=q.front();
            q.pop();
            if(ret->val>tmp->val)
            {
                ret=tmp;
            }
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        if(root->val>ret->val)
            return ret;
        return NULL;
    }
    void recoverTree(TreeNode* root) {
        if(flag==1)
            return;
        if(!(root))
            return;
        TreeNode*a,*b;
        
        a=helper_left(root,root->left);
        b=helper_right(root,root->right);
        
        if(a and b)
        {
            swap(a->val,b->val);
            flag=1;
            return;
        }
        else if(a)
        {
            swap(root->val,a->val);
            flag=1;
            return;
        }
        else if(b)
        {
            swap(root->val,b->val);
            flag=1;
            return;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
};