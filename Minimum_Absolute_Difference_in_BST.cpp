class Solution {
public:
    void helper(TreeNode* root,vector<int> &v)
    {
        if(!(root))
            return;
        v.push_back(root->val);
        helper(root->left,v);
        helper(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        vector<int>v;
        helper(root,v);
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
            ans=min(ans,v[i]-v[i-1]);
        return ans;
    }
};