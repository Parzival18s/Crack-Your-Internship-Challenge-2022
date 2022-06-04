class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(((p->val>root->val) and (q->val<root->val)) or ((p->val<root->val) and q->val>root->val) or 
          (p->val==root->val) or (q->val==root->val))
            return root;
        if((p->val>root->val) and (q->val>root->val))
            return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};