class Solution {
public:
    void erase(vector<vector<int>>&grid,int i,int j,vector<pair<int,int>>&v)
    {
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size())
            return;
        if(grid[i][j]==0 or grid[i][j]==2)
            return;
        grid[i][j]=2;
        v.push_back({i,j});
        erase(grid,i+1,j,v);
        erase(grid,i,j+1,v);
        erase(grid,i-1,j,v);
        erase(grid,i,j-1,v);
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>>v1,v2;
        int a=-1,b=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    a=i;
                    b=j;
                    erase(grid,a,b,v1);
                    break;
                }
            }
            if(a!=-1)
                break;
        }
        a=-1;
        b=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    a=i;
                    b=j;
                    erase(grid,a,b,v2);
                    break;
                }
            }
            if(a!=-1)
                break;
        }
        int ans=INT_MAX;
        for(int i=0;i<v1.size();i++)
        {
            int tmp=INT_MAX;
            for(int j=0;j<v2.size();j++)
                tmp=min(tmp,abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second));
            ans=min(ans,tmp);
        }
        return ans-1;
    }
};