class Solution {
public:
    vector<int> productArray(vector<int>arr)
    {
        int n=arr.size();
        if(n==1)
            return arr;
        int i,tmp=1;
        vector<int>ans(n,1);
        for (i=0;i<n;i++)
        {
            ans[i]=tmp;
            tmp*=arr[i];
        }
        tmp=1;
        for(i=n-1;i>=0;i--)
        {
            ans[i]*=tmp;
            tmp*=arr[i];
        }
        return ans;
    }
};