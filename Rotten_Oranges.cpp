class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m,n;
        n=grid.size();
        m=grid[0].size();
        int t=0,flag=0,tmp=0;
        while(1)
        {
            tmp=0;
            flag=0;
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                    {
                        if(i>0 and grid[i-1][j]==2)
                        {
                            v.push_back(i);
                            v.push_back(j);
                            tmp++;
                        }
                        if(i<n-1 and grid[i+1][j]==2)
                        {
                            v.push_back(i);
                            v.push_back(j);
                            tmp++;
                        }
                        if(j>0 and grid[i][j-1]==2)
                        {
                            v.push_back(i);
                            v.push_back(j);
                            tmp++;
                        }
                        if(j<m-1 and grid[i][j+1]==2)
                        {
                            v.push_back(i);
                            v.push_back(j);
                            tmp++;
                        }
                        if(tmp==0)
                            flag=1;
                    }
                }
            }
            if(tmp==0)
                break;
            for(int i=0;i<v.size();i+=2)
            {
                grid[v[i]][v[i+1]]=2;
            }
            t++;
        }
        if(flag==1)
            return -1;
        return t;
    }
};