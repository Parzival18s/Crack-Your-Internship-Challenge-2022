class Solution {
public:
    int fun(int n,vector<int>&v)
    {
        if(v[n]!=-1)
            return v[n];
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        v[n]=fun(n-1,v)+fun(n-2,v);
        return v[n];
    }
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        return fun(n,v);
    }
};