class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+2,vector<int>(grid[0].size()+2,INT_MAX));
        int ans=INT_MIN,land=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i+1][j+1]=0;
                    land++;
                }
            }
        }
        if(land==0 or land==grid.size()*grid[0].size())
            return -1;
        while(1)
        {
            int change=0;
            for(int i=1;i<=grid.size();i++)
            {
                for(int j=1;j<=grid[0].size();j++)
                {
                    if(dp[i][j]!=0)
                    {
                        if(dp[i+1][j]!=INT_MAX or dp[i-1][j]!=INT_MAX 
                           or dp[i][j+1]!=INT_MAX or dp[i][j-1]!=INT_MAX)
                        {
                            int tmp=1+min(min(dp[i+1][j],dp[i-1][j]),min(dp[i][j+1],dp[i][j-1]));
                            if(dp[i][j]!=tmp)
                            {
                                change++;
                                dp[i][j]=tmp;
                            }
                        }
                    }
                }
            }
            if(change==0)
                break;
        }
        for(int i=1;i<=grid.size();i++)
        {
            for(int j=1;j<=grid[0].size();j++)
                ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};