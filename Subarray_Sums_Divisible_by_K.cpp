class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int ans=0,n=nums.size();
	    unordered_map<int,int> m;
	    int sum=0;
	    m[0]=1;
	    for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
		    int rem=sum%k;
            while(rem<0)
                rem+=k;
		    if(m.find(rem)!=m.end())
                ans+=m[rem];
		    m[rem]++;
	    }
	    return ans;
    }
};