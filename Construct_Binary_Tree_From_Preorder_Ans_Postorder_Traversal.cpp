class Solution {
public:
    TreeNode* helper(vector<int>& pre,unordered_map<int,int>& mp,int& preorderIndex)
    {
        int curr=pre[preorderIndex];
        TreeNode* n=new TreeNode(curr);
        preorderIndex++;
        if(preorderIndex<pre.size()  && mp[pre[preorderIndex]]<mp[curr])
            n->left=helper(pre,mp,preorderIndex);
        else 
            return n;
        if(preorderIndex<pre.size() && mp[pre[preorderIndex]]<mp[curr])
            n->right=helper(pre,mp,preorderIndex);
        return n;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {        
        unordered_map<int,int>mp;
        for(int i=0;i<post.size();i++)
            mp[post[i]]=i;
        int preorderIndex=0;
        return helper(pre,mp,preorderIndex);
    }
};