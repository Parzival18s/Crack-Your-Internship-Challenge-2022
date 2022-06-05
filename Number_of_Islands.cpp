class Solution {
public:
    void helper(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='#';
        if((i>0) and (grid[i-1][j]=='1'))
           helper(grid,i-1,j);
        if((i<grid.size()-1) and (grid[i+1][j]=='1'))
            helper(grid,i+1,j);
        if((j>0) and (grid[i][j-1]=='1'))
           helper(grid,i,j-1);
        if((j<grid[i].size()-1) and (grid[i][j+1]=='1'))
            helper(grid,i,j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};