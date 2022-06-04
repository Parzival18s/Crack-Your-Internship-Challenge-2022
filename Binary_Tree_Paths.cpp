class Solution {
public:
    void helper(TreeNode* root,vector<string> &v,string str)
    {
        str+=to_string(root->val);
        if((!(root->left)) and (!(root->right)))
        {
            v.push_back(str);
            return;
        }
        str+="->";
        if(root->left)
            helper(root->left,v,str);
        if(root->right)
            helper(root->right,v,str);
        return;
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string str="";
        helper(root,v,str);
        return v;
    }
};