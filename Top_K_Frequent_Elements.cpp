class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        unordered_map<int,int>m;
        multimap<int,int>mp;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto &i:m)
            mp.insert({i.second,i.first});
        auto it=mp.end();
        while(k--)
        {
            it--;
            v.push_back(it->second);
        }
        return v;
    }
};