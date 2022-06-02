class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int s=nums[0],e=nums[0];
        s=nums[s];
        e=nums[nums[e]];
        while(s!=e)
        {
            s=nums[s];
            e=nums[nums[e]];
        }
        s=nums[0];
        while(s!=e)
        {
            s=nums[s];
            e=nums[e];
        }
        return s;
    }
};