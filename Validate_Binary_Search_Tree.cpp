class Solution {
public:
    void helper(TreeNode* root,vector<int>& v)
    {
        if(root->left)
            helper(root->left,v);
        v.push_back(root->val);
        if(root->right)
            helper(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
                return false;
        }
        return true;
    }
};