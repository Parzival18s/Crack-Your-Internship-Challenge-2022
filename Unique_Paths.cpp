class Solution {
public:
    int arr[101][101];
    int helper(int i,int j)
    {
        if(arr[i][j]!=-1)
            return arr[i][j];
        int t1=helper(i+1,j);
        int t2=helper(i,j+1);
        return arr[i][j]=t1+t2;
    }
    int uniquePaths(int m, int n) {
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<m;i++)
            arr[i][n-1]=1;
        for(int i=0;i<n;i++)
            arr[m-1][i]=1;
        int ans=helper(0,0);
        return ans;
    }
};