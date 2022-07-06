class Solution {
public:
    int floor(vector<int> nums, int target)
    {
        int n=nums.size()-1,i=0;
        if(nums[i]>target)
            return -1;
        while(i<=n and nums[i]<=x)
            i++;
        return nums[i-1];
    }

    int ceiling(vector<int> nums,int target)
    {
        int n=nums.size()-1;
        if(nums[n]<target)
            return -1;
        while(n>=0 and nums[n]>=x)
            n--;
        return nums[n+1];
    }
};