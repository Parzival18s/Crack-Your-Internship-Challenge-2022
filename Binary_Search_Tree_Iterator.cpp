class BSTIterator {
public:
    vector<int>v;
    int i=-1;
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(root->left)
            inorder(root->left,v);
        v.push_back(root->val);
        if(root->right)
            inorder(root->right,v);
    }
    BSTIterator(TreeNode* root) {
        inorder(root,v);
    }
    
    int next() {
        
        i++;
        return v[i];
    }
    
    bool hasNext() {
        if(i==v.size()-1)
            return false;
        return true;
    }
};