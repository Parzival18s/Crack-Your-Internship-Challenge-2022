class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>nums,vector<int>v,int i)
    {
        if(i==nums.size())
        {
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        vector<int>u;
        u=v;
        u.push_back(nums[i]);
        helper(nums,v,i+1);
        helper(nums,u,i+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        helper(nums,tmp,0);
        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};