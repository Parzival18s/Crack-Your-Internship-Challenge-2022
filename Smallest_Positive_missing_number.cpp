class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    { 
        sort(arr,arr+n);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                if(arr[i]==ans)
                    ans++;
            }
        }
        return ans;
    } 
};