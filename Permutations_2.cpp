class Solution {
public:
    void helper(vector<int>&nums,int i,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            s.insert(nums);
            return ;  
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            helper(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
       vector<vector<int>>ans;
        helper(nums,0);
        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};