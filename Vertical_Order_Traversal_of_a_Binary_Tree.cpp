unordered_map<TreeNode*,int>v;
bool helper(TreeNode* a,TreeNode* b)
{
    return v[a]<v[b];
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<TreeNode*>>m;
        unordered_map<TreeNode*,int>u;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int i=0,j=0;
        m[j].push_back(root);
        u[root]=0;
        v[root]=0;
        while(!q.empty())
        {
            i=v[q.front()];
            j=u[q.front()];
            if(q.front()->left)
            {
                m[j-1].push_back(q.front()->left);
                q.push(q.front()->left);
                u[q.front()->left]=j-1;
                v[q.front()->left]=i+1;
            }
            if(q.front()->right)
            {
                m[j+1].push_back(q.front()->right);
                q.push(q.front()->right);
                u[q.front()->right]=j+1;
                v[q.front()->right]=i+1;
            }
            q.pop();
        }
        for(auto &i:m)
        {
            sort(i.second.begin(),i.second.end(),helper);
            for(int j=0;j<i.second.size()-1;j++)
            {
                if(v[i.second[j]]==v[i.second[j+1]])
                {
                    if(i.second[j]->val>i.second[j+1]->val)
                    {
                        swap(i.second[j],i.second[j+1]);
                        j=-1;
                    }
                }
            }
            vector<int>tmp;
            for(int j=0;j<i.second.size();j++)
                tmp.push_back(i.second[j]->val);
            ans.push_back(tmp);
        }
        return ans;
    }
};