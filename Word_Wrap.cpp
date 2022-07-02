class Solution {
public:
    int dp[501][2001];
    int solve(vector<int> nums,int ind,int rem,int k){
        if(ind==nums.size())
            return 0;
        
        if(dp[ind][rem]!=-1)
            return dp[ind][rem];
        
        if(nums[ind]>rem)
            return dp[ind][rem]=pow(rem+1,2)+solve(nums,ind+1,k-nums[ind]-1,k);
        
        int choice1=solve(nums,ind+1,rem-nums[ind]-1,k);
        int choice2=pow(rem+1,2)+solve(nums,ind+1,k-nums[ind]-1,k);
        
        return dp[ind][rem]=min(choice1,choice2);
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        return solve(nums,0,k,k);
    }
};