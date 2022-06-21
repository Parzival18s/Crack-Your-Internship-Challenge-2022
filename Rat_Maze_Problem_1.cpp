class Solution{
    public:
    void helper(vector<vector<int>>&m,int i,int j,string tmp,vector<string>& ans,int n)
    {
        if(i<0 or j<0 or i==n or j==n)
            return;
        if(m[i][j]==0)
            return;
        if(i==n-1 and j==n-1)
        {
            ans.push_back(tmp);
            return;
        }
        m[i][j]=0;
        helper(m,i-1,j,tmp+"U",ans,n);
        helper(m,i+1,j,tmp+"D",ans,n);
        helper(m,i,j-1,tmp+"L",ans,n);
        helper(m,i,j+1,tmp+"R",ans,n);
        m[i][j]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string tmp="";
        helper(m,0,0,tmp,ans,n);
        return ans;
    }
};