class Solution{
public:
    int helper(int arr[],int i,int sum,int& flag)
    {
        if(flag==1)
            return 1;
        if(sum<0 or i<0)
            return 0;
        if(sum==0)
        {
            flag=1;
            return 1;
        }
        int t1,t2;
        t1=helper(arr,i-1,sum-arr[i],flag);
        t2=helper(arr,i-1,sum,flag);
        if(t1>0 or t2>0)
        {
            flag=1;
            return 1;
        }
        return 0;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0,flag=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2)
            return 0;
        sum/=2;
        sort(arr,arr+N);
        if(helper(arr,N-1,sum,flag)>0)
            return 1;
        return 0;
    }
};