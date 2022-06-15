class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!(root))
            return v;
        queue<TreeNode*>q;
        q.push(root);
        int c=0;
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
            if(c%2)
                reverse(t.begin(),t.end());
            c++;
            v.push_back(t);
        }
        return v;
    }
};