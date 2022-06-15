class Solution {
public:
    void helper(TreeNode* root,int target,int sum,int& ans,int flag)
    {
        if(!(root))
            return;
        if(flag==0)
        {
            helper(root->left,target,sum,ans,0);
            helper(root->right,target,sum,ans,0);
        }
        long long check=sum;
        check+=root->val;
        if(check>INT_MAX)
            return;
        sum+=root->val;
        helper(root->left,target,sum,ans,1);
        helper(root->right,target,sum,ans,1);
        if(target==sum)
            ans++;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0,sum=0;
        if(!(root))
            return ans;
        helper(root,targetSum,sum,ans,0);
        return ans;
    }
};