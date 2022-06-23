class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans=0;
        int arr[n+1][m+1];
        for(int i=0;i<=m;i++)
            arr[0][i]=0;
        for(int i=0;i<=n;i++)
            arr[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                    arr[i][j]=arr[i-1][j-1]+1;
                else
                    arr[i][j]=0;
                ans=max(ans,arr[i][j]);
            }
        }
        return ans;
    }
};