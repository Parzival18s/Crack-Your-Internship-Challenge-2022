class Solution {
public:
    int helper(TreeNode* root)
    {
        if(!(root))
            return 0;
        return 1+max(helper(root->left),helper(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!(root))
            return true;
        queue<TreeNode*>q;
        q.push(root);
        while(!(q.empty()))
        {
            int hl,hr;
            hl=helper(q.front()->left);
            hr=helper(q.front()->right);
            if((abs(hl-hr))>1)
                return false;
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
                     
        }
        return true;
        
    }
};