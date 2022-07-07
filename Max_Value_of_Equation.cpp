class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans=INT_MIN;
        int i=0,j=1;
        while(j<points.size())
        {
            if(i!=j and abs(points[j][0]-points[i][0])<=k)
                ans=max(ans,(points[j][1]+points[i][1]+abs(points[j][0]-points[i][0])));
            while(i<j and abs(points[j][0]-points[i][0])>k)
                i++;
            if(i!=j and abs(points[j][0]-points[i][0])<=k)
                ans=max(ans,(points[j][1]+points[i][1]+abs(points[j][0]-points[i][0])));
            if(j!=points.size()-1 and points[j][1]-points[i][1]>abs(points[j][0]-points[i][0]))
                i=j;
            j++;
        }
        j--;
        while(i<j)
        {
            if(i!=j and abs(points[j][0]-points[i][0])<=k)
                ans=max(ans,(points[j][1]+points[i][1]+abs(points[j][0]-points[i][0])));
            i++;
        }
        return ans;
    }
};