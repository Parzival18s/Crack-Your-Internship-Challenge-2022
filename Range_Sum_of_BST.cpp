class Solution {
public:
    void helper(TreeNode*root,int &ans,int low,int high)
    {
        if(!(root))
            return;
        if((root->val<=high) and (root->val>=low))
            ans+=root->val;
        helper(root->left,ans,low,high);
        helper(root->right,ans,low,high);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        helper(root,ans,low,high);
        return ans;
    }
};