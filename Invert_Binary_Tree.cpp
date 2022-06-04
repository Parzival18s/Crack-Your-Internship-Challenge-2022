class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!(root))
            return root;
        queue<TreeNode*>q;
        TreeNode *ptr1,*ptr2;

        q.push(root);
        
        while(!(q.empty()))
        {
            ptr1=q.front();
            ptr2=ptr1->left;
            ptr1->left=ptr1->right;
            ptr1->right=ptr2;
            q.pop();
            if(ptr1->left)
                q.push(ptr1->left);
            if(ptr1->right)
                q.push(ptr1->right);
        }
        
        return root;
    }
};