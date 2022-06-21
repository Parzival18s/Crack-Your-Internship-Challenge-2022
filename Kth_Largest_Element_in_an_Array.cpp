class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i:nums)
            m[i]++;
        auto it=m.end();
        it--;
        while(1)
        {
            if(k>it->second)
            {
                k-=it->second;
                it--;
            }
            else
                break;
        }
        return it->first;
    }
};