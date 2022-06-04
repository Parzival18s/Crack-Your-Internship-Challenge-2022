class Solution {
public:
    bool helper(TreeNode* root,int targetSum)
    {
        if(!(root))
            return false;
        if((targetSum==root->val) and ((!(root->left)) and (!(root->right))))
            return true;
        return (helper(root->left,targetSum-root->val) or helper(root->right,targetSum-root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!(root))
            return false;
        if((!(root->left)) and (!(root->right)))
        {
            if(targetSum==root->val)
                return true;
            return false;
        }
        return (helper(root->left,targetSum-root->val) or helper(root->right,targetSum-root->val));
    }
};