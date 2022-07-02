class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1,n=points.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<float,int>slope;
            int p=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(points[i][0]==points[j][0])
                    {
                        slope[INT_MAX]++;
                        p=max(p,slope[INT_MAX]);
                    }
                    else if(points[i][1]==points[j][1])
                    {
                        slope[INT_MIN]++;
                        p=max(p,slope[INT_MIN]);
                    }
                    else
                    {
                        float tmp=((points[i][1]-points[j][1])*(0.1))/(points[i][0]-points[j][0]);
                        slope[tmp]++;
                        p=max(p,slope[tmp]);
                    }
                }
                ans=max(ans,p+1);
            }
        }
        return ans;
    }
};