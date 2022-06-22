class Solution
{
    public:
    int helper(vector<int>& arr,int n,int x,int y,int z)
    {
        if(n==0)
            return 0;
        if(n<x)
            return INT_MIN;
        if(arr[n]!=-1)
            return arr[n];
        int t1,t2,t3,t4,t5;
        t1=helper(arr,n-x,x,y,z);
        t2=helper(arr,n-y,x,y,z);
        t3=helper(arr,n-z,x,y,z);
        t4=max(t1,t2);
        t5=max(t2,t3);
        return arr[n]=1+max(t4,t5);
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>arr(n+1,-1),v;
        int a,b,c;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(),v.end());
        a=v[0];
        b=v[1];
        c=v[2];
        arr[n]=helper(arr,n,a,b,c);
        if(arr[n]<0)
            arr[n]=0;
        return arr[n];
    }
};