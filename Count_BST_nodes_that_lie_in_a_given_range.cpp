class Solution{
public:
    void helper(Node* root,vector<int>& v)
    {
        if(!(root))
            return;
        if(root->left)
            helper(root->left,v);
        v.push_back(root->data);
        if(root->right)
            helper(root->right,v);
        return;
    }
    int getCount(Node *root, int l, int h)
    {
        vector<int>v;
        helper(root,v);
        int i=0,j=v.size()-1;
        if(l>v[j] or h<v[i])
            return 0;
        while(v[i]<l)
            i++;
        while(v[j]>h)
            j--;
        return j-i+1;
    }
};