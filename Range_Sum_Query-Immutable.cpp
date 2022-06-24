class NumArray {
public:
    vector<int>helper;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            helper.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return helper[right];
        return (helper[right]-helper[left-1]);
    }
};