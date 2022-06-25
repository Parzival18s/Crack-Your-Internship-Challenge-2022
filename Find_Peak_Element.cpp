class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int m=(i+j)/2;
            if((m==nums.size()-1 or nums[m]>nums[m+1]) and (m==0 or nums[m]>nums[m-1]))
            {
                i=m;
                break;
            }
            else if(m>0 and nums[m-1]>nums[m])
                j=m-1;
            else
                i=m+1;
        }
        return i;
    }
};