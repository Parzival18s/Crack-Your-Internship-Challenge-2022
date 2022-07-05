class Solution
{
	public:
	stack<int>s;
	vector<bool>visited;
	void helper(int i,vector<int>adj[])
	{
	    if(visited[i])
	        return;
	    visited[i]=true;
	    for(int j=0;j<adj[i].size();j++)
	    {
	        if(!visited[adj[i][j]])
	            helper(adj[i][j],adj);
	    }
	    s.push(i);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    for(int i=0;i<V;i++)
	        visited.push_back(false);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	            helper(i,adj);
	    }
	    vector<int>ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};