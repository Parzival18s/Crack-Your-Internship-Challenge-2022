class NumMatrix {
public:
    vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>pre;
            int tmp=0;
            for(int j=0;j<matrix[i].size();j++)
            {
                tmp+=matrix[i][j];
                pre.push_back(tmp);
            }
            v.push_back(pre);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        if(col1==0)
        {
            for(int i=row1;i<=row2;i++)
                ans+=v[i][col2];
        }
        else
        {
            for(int i=row1;i<=row2;i++)
                ans+=v[i][col2]-v[i][col1-1];
        }
        return ans;
    }
};