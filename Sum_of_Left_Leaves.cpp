class Solution {
public:
    void helper(TreeNode* root,int &ans,int f)
    {
        if(!(root))
            return;
        if((!(root->left)) and (!(root->right)))
        {
            if(f==0)
                return;
            ans+=root->val;
            return;
        }
        helper(root->left,ans,1);
        helper(root->right,ans,0);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        helper(root,ans,0);
        return ans;
    }
};