class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        multimap<float,int>m;
        float tmp;
        for(int i=0;i<points.size();i++)
        {
            tmp=float(sqrt(pow(points[i][0],2)+pow(points[i][1],2)));
            m.insert({tmp,i});
        }
        auto it=m.begin();
        for(int i=0;i<k;i++)
        {
            vector<int>u;
            u.push_back(points[it->second][0]);
            u.push_back(points[it->second][1]);
            ans.push_back(u);
            it++;
        }
        return ans;
    }
};