class Solution {
public:
    void flatten(TreeNode* root) {
        if(!(root))
            return;
        TreeNode* ptr;
        ptr=root;
        stack<TreeNode*>s;
        h1:while((ptr) and (ptr->left or ptr->right))
        {
            if(ptr->right)
                s.push(ptr->right);
            ptr->right=ptr->left;
            ptr->left=NULL;
            ptr=ptr->right;
        }
        ptr=root;
        while(ptr->right)
            ptr=ptr->right;
        while(!(s.empty()))
        {
            ptr->left=NULL;
            ptr->right=s.top();
            ptr=s.top();
            s.pop();
            if(ptr->left)
                goto h1;
            if(ptr->right)
                s.push(ptr->right);
        }
        return;
    }
};