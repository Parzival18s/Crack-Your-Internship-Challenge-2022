public:
    int v[15][10005];
    int helper(vector<int>&coins,int am,int i)
    {
        if(i<0 or am<0)
        {
            return INT_MAX-4;
        }
        if(v[i][am]!=-1)
            return v[i][am];
        if(am==0)
        {
            v[i][am]=0;
            return 0;
        }
        return v[i][am]=min(1+helper(coins,am-coins[i],i),helper(coins,am,i-1));
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans,n;
        memset(v,-1,sizeof(v));
        n=coins.size()-1;
        ans=helper(coins,amount,n);
        if(ans>10000)
            ans=-1;
        return ans;
    }
};