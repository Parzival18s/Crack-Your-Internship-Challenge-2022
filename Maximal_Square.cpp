class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>v(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i>0 and j>0)
                        v[i][j]=min(min(v[i-1][j],v[i][j-1]),v[i-1][j-1])+1;
                    else
                        v[i][j]=1;
                    ans=max(ans,v[i][j]*v[i][j]);
                }
            }
        }
        return ans;
    }
};