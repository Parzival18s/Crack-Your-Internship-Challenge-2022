class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int p2=1,p3=1,p5=1;
        for(int i=2;i<=n;i++)
        {
            int f2=2* dp[p2];
            int f3=3* dp[p3];
            int f5=5* dp[p5];
            int mn=min(f5,min(f2, f3));
            dp[i]=mn;
            if(mn==f2)
                p2++;
            if(mn==f3)
                p3++;
            if(mn==f5)
                p5++;
        }
        return dp[n];
    }
};