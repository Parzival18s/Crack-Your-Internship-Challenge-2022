class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!(root))
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!(q.empty()))
        {
            int tmp=q.size();
            vector<int>t;
            for(int i=0;i<tmp;i++)
            {
                t.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            v.push_back(t);
        }
        return v;
    }
};