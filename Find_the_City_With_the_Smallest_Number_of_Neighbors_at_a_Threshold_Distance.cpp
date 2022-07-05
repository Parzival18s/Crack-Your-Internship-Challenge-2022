class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int y=1e6;
        vector<vector<int>>dis(n,vector<int>(n,y));
        for(int i=0;i<edges.size();i++)
        {
            dis[edges[i][0]][edges[i][1]]=edges[i][2];
            dis[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                dis[i][i]=0;
                for(int j=0;j<n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        int x=n,ans=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=x)
            {
                x=cnt;
                ans=i;
            }
        }
        return ans;
    }
};