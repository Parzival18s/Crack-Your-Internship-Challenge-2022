class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN,b=INT_MIN,c=INT_MIN,d=INT_MAX,e=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>c)
            {
                a=b;
                b=c;
                c=nums[i];
            }
            else if(nums[i]>b)
            {
                a=b;
                b=nums[i];
            }
            else if(nums[i]>a)
                a=nums[i];
            if(nums[i]<d)
            {
                e=d;
                d=nums[i];
            }
            else if(nums[i]<e)
                e=nums[i];
        }
        return max(a*b*c,d*e*c);
    }
};