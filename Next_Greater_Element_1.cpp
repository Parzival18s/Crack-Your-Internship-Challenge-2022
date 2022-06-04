class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>s;
        for(int i=0;i<nums2.size();i++)
        {
            while(!s.empty()&&nums2[i]>s.top())
            {
                mp[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty())
        {
            mp[s.top()]=-1;
            s.pop();
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};