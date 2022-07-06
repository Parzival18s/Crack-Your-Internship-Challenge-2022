class Solution {
public:

    int minCostToMakeElementEqual(vector<int>arr) {
        int n=arr.size();
        int tmp,ans=0;
        if (n%2)
            tmp=a[n/2];
        else
            tmp=(arr[n/2]+arr[(n-2)/2])/2;
        for(int i=0;i<n;i++)
            ans+=abs(arr[i]-tmp);
        return ans;
    }
};