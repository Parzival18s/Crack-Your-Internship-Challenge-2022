class Solution {
public:
    int ans=INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int t1,t2;
        t1=helper(root->left);
        t2=helper(root->right);
        if(t1<0)
            t1=0;
        if(t2<0)
            t2=0;
        ans=max(ans,t1+t2+root->val);
        return root->val+max(t1,t2);
    }
    int maxPathSum(TreeNode* root) {
        int x=helper(root);
        ans=max(ans,x);
        return ans;
    }
};