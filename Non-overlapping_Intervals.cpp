class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        unordered_set<int>s;
        map<int,int>m;
        for(int i=0;i<intervals.size();i++)
        {
            if(!(s.count(intervals[i][0])))
            {
                s.insert(intervals[i][0]);
                m[intervals[i][0]]=intervals[i][1];
            }
            else
            {
                m[intervals[i][0]]=min(m[intervals[i][0]],intervals[i][1]);
                ans++;
            }
        }
        vector<vector<int>>v;
        for(auto &i:m)
            v.push_back({i.first,i.second});
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i][1]>v[i+1][0])
            {
                ans++;
                v[i+1][1]=min(v[i+1][1],v[i][1]);
            }
        }
        return ans;
    }
};