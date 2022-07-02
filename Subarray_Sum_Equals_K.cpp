class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,tmp=0,p;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            tmp+=nums[i];
            if(tmp==k)
                ans++;
            p=tmp-k;
            if(m.find(p)!=m.end())
                ans+=m[p];
            m[tmp]++;
        }
        return ans;
    }
};