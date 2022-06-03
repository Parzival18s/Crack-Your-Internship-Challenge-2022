class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    long long ans=INT_MAX,i=0;
    sort(a.begin(),a.end());
    while(i+m-1<n)
    {
        ans=min(ans,a[i+m-1]-a[i]);
        i++;
    }
    return ans;
    }   
};
