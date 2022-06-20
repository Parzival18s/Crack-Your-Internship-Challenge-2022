void inorder(Node* root,vector<int>&v,unordered_set<int>&s)
{
    if(!(root))
        return;
    if((!(root->left)) and (!(root->right)))
        s.insert(root->data);
    inorder(root->left,v,s);
    v.push_back(root->data);
    inorder(root->right,v,s);
}
bool isDeadEnd(Node *root)
{
    vector<int>v;
    unordered_set<int>s;
    inorder(root,v,s);
    int n=v.size()-1;
    if(n<3)
        return false;
    for(int i=1;i<v.size()-1;i++)
    {
        if(((v[i]-v[i-1])==1) and ((v[i+1]-v[i])==1) and (s.count(v[i])))
            return true;
    }
    if((v[0]==1) and(v[1]==2) and s.count(v[0]))
        return true;
    return false;
}