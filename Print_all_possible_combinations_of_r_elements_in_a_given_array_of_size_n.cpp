class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>v,vector<int>c,int n,int r,int in)
    {
        if(r==0)
        {
            ans.push_back(c);
            return;
        }
        if(in==n)
            return;
        if(n-in==r)
        {
            for(int i=in;i<n;i++)
                c.push_back(v[i]);
            ans.push_back(c);
            return;
        }
        if(n-in<r)
            return;
        vector<int>u;
        u=c;
        u.push_back(v[in]);
        helper(v,c,n,r,in+1);
        helper(v,u,n,r-1,in+1);
        return;
    }
    vector<vector<int>> combinations(vector<int>v,int n,int r)
    {
        vector<int>c;
        helper(v,c,n,r,0);
        return ans;
    }
};