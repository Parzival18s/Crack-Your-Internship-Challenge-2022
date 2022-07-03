class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>>pq;
        double tmp;
        for(int i=0;i<points.size();i++)
        {
            tmp=(pow(points[i][0],2)+pow(points[i][1],2))*(0.1);
            pq.push({tmp,{points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            vector<int>x;
            pair<double,pair<int,int>>y=pq.top();
            pq.pop();
            x.push_back(y.second.first);
            x.push_back(y.second.second);
            ans.push_back(x);
        }
        return ans;
    }
};
