class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        stack<int>s,t;
        int n=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() and s.top()>nums[i] and n>0)
            {
                s.pop();
                n--;
            }
            s.push(nums[i]);
        }
        while(!s.empty())
        {
            t.push(s.top());
            s.pop();
        }
        while(k--)
        {
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
    }
};