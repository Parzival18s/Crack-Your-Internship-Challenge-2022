class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxp=0,minp=0,ans=0;
        int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                swap(maxp,minp); 
           maxp=max((long long)nums[i],nums[i]*maxp);
	       minp=min((long long)nums[i],nums[i]*minp);
           ans=max(ans,maxp);
        }
        return ans;
    }
};