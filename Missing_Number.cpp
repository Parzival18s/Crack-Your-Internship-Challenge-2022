class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>arr(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
            arr[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(arr[i]==0)
                return i;
        }
        return nums.size();
    }
};