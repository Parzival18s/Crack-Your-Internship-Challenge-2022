class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!(root))
            return root;
        if(root->val==p->val or root->val==q->val)
            return root;
       root->left=lowestCommonAncestor(root->left,p,q);
       root->right=lowestCommonAncestor(root->right,p,q);
        if(!(root->left))
            return root->right;
        if(!(root->right))
            return root->left;
        return root;
    }
};