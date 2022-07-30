class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "NULL,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        string tmp="";
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(tmp);
                tmp="";
            }
            else
                tmp+=data[i];
        }
        if(tmp.size()>0)
            q.push(tmp);
        return helper(q);
    }
    
    TreeNode* helper(queue<string>&q)
    {
        if(q.front()=="NULL")
            return NULL;
        TreeNode* root=new TreeNode(stoi(q.front()));
        q.pop();
        root->left=helper(q);
        q.pop();
        root->right=helper(q);
        return root;
    }
};