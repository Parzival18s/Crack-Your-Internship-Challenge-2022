class Solution {
  public:
    bool helper(vector<int>adj[],int curr,int parent,vector<bool>&visit)
    {
       visit[curr]=true;
       bool status=false;
       for(auto x:adj[curr])
       {
           if(!visit[x])
               status|=helper(adj,x,curr,visit);
           else if(visit[x] && x!=parent)
               return true;
       }
       return status;
   }
   
    bool isCycle(int V, vector<int>adj[])
    {
        vector<bool>visit(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visit[i] && helper(adj,i,-1,visit))
                return true;
        }
        return false;
    }
};