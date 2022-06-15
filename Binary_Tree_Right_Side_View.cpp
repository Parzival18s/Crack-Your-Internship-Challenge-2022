class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!(root))
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!(q.empty()))
        {
            int tmp=q.size();
            for(int i=0;i<tmp-1;i++)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};