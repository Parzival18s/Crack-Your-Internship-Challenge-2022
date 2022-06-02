class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        int n=nums.size();
        while(i<n and j<n)
        {
            if(nums[i]==0 and nums[j]!=0)
            {
                nums[i]=nums[j];
                nums[j]=0;
                i++;
                j++;
            }
            else if(nums[i]==0 and nums[j]==0)
            {
                j++;
            }
            else if(nums[i]!=0)
            {
                i++;
                j++;
            }
        }
    }
};