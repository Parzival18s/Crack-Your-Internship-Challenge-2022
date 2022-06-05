class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_set<int>s;
        queue<int>q;
        int tmp;
        q.push(0);
        while(!(q.empty()))
        {
            tmp=q.front();
            ans.push_back(tmp);
            s.insert(tmp);
            q.pop();
            for(int i=0;i<adj[tmp].size();i++)
            {
                if(!(s.count(adj[tmp][i])))
                {
                    q.push(adj[tmp][i]);
                    s.insert(adj[tmp][i]);
                }
            }
        }
        return ans;
    }
};