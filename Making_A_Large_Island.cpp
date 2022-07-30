class Solution {
public:
    int row,col;
    bool isvalid(int i,int j)
    {
        if(i<0 or j<0 or i==row or j==col)
            return false;
        return true;
    }
    int helper(vector<vector<int>>&v,int i,int j,int k)
    {
        if(v[i][j]!=1)
            return 0;
        v[i][j]=k;
        int a=0,b=0,c=0,d=0;
        if(isvalid(i+1,j))
            a=helper(v,i+1,j,k);
        if(isvalid(i-1,j))
            b=helper(v,i-1,j,k);
        if(isvalid(i,j+1))
            c=helper(v,i,j+1,k);
        if(isvalid(i,j-1))
            d=helper(v,i,j-1,k);
        return 1+a+b+c+d;
    }
    int largestIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int k=2,tmp,ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    tmp=helper(grid,i,j,k);
                    m[k]=tmp;
                    ans=max(ans,tmp);
                    k++;
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    tmp=1;
                    unordered_set<int>s;
                    if(isvalid(i-1,j))
                        s.insert(grid[i-1][j]);
                    if(isvalid(i+1,j))
                        s.insert(grid[i+1][j]);
                    if(isvalid(i,j-1))
                        s.insert(grid[i][j-1]);
                    if(isvalid(i,j+1))
                        s.insert(grid[i][j+1]);
                    for(auto i:s)
                        tmp+=m[i];
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;
    }
};