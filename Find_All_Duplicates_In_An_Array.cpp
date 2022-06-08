class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+1,0),ans;
        for(int i=0;i<nums.size();i++)
            arr[nums[i]]++;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==2)
                ans.push_back(i);
        }
        return ans;
    }
};