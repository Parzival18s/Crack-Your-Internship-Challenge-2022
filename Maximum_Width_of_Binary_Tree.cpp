class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*>qn;
        queue<int>qv;
        TreeNode*tmp;
        qn.push(root);
        qv.push(1);
        int ans=0;
        while(!qn.empty())
        {
            int x=qn.size(),mn=INT_MAX,mx=INT_MIN;
            int p=qv.front();
            for(int i=0;i<x;i++)
            {
                tmp=qn.front();
                if(i==0)
                    mn=qv.front();
                if(i==x-1)
                    mx=qv.front();
                int y=qv.front()-p+1;
                if(tmp->left)
                {
                    qn.push(tmp->left);
                    qv.push(2LL*y);
                }
                if(tmp->right)
                {
                    qn.push(tmp->right);
                    qv.push(2LL*y+1);
                }
                qn.pop();
                qv.pop();
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};