class Solution {
public:
    unordered_map<int,int>parent;
    int helper(int a)
    {
        if(parent[a]==a)
            return a;
        return parent[a]=helper(parent[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        for(int i=1;i<=edges.size();i++)
            parent[i]=i;
        for(int i=0;i<edges.size();i++)
        {
            int a=helper(edges[i][0]);
            int b=helper(edges[i][1]);
            if(a==b)
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
            parent[b]=a;
        }
        return ans;
    }
};