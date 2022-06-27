class Solution {
public:
    void helper(int n,int k,vector<int>c,vector<vector<int>>&ans)
    {
        if(k==0)
        {
            ans.push_back(c);
            return;
        }
        if(n<1)
            return;
        if(n==k)
        {
            for(int i=n;i>0;i--)
                c.push_back(i);
            ans.push_back(c);
            return;
        }
        vector<int>v;
        v=c;
        v.push_back(n);
        n--;
        helper(n,k,c,ans);
        helper(n,k-1,v,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>c;
        vector<vector<int>>ans;
        helper(n,k,c,ans);
        return ans;
    }
};