class Solution {
public:
    void helper(TreeNode* root,vector<int> &v)
    {
        if(!(root))
            return;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        return v;
    }
};