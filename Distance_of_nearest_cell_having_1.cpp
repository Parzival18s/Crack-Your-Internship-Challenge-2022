class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n,m,c,d,e;
	    n=grid.size();
	    m=grid[0].size();
	    vector<vector<int>>v(n+2,vector<int>(m+2,INT_MAX-1000)),a(n,vector<int>(m,INT_MAX-1000));
	    while(1)
	    {
	        int tmp=0;
	        for(int i=n-1;i>=0;i--)
	        {
	            for(int j=m-1;j>=0;j--)
	            {
	                if(grid[i][j]==1)
	                {
	                    v[i+1][j+1]=0;
	                    a[i][j]=0;
	                }
	                else    
	                {
	                    int old=a[i][j];
	                    c=min(v[i+1][j],v[i+1][j+2]);
	                    d=min(v[i+2][j+1],v[i][j+1]);
	                    e=min(c,d);
	                    a[i][j]=1+min(a[i][j],e);
	                    v[i+1][j+1]=a[i][j];
	                    if(a[i][j]!=old)
	                        tmp++;
	                }
	            }
	        }
	        if(tmp==0)
	            break;
	    }
	    return a;
	}
};