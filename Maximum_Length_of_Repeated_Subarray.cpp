class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int m=nums1.size(),n=nums2.size();
        int arr[m+1][n+1];
        for(int i=0;i<=n;i++)
            arr[0][i]=0;
        for(int i=0;i<=m;i++)
            arr[i][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                    ans=max(ans,arr[i][j]);
                }
                else
                    arr[i][j]=0;
            }
        }
        return ans;
    }
};