class Solution{
	public:
	long long getCount(int N)
	{
		vector<vector<long long>>v(4,vector<long long>(3,1));
		v[0][0]=0;
		v[0][2]=0;
		N--;
		long long a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,ans=0;
		while(N--)
		{
		    a=v[1][1];
		    b=v[1][1]+v[2][0];
		    c=v[0][1]+v[1][0]+v[1][2]+v[2][1];
		    d=v[1][1]+v[2][2];
		    e=v[1][0]+v[2][1]+v[3][0];
		    f=v[2][0]+v[2][2]+v[1][1]+v[3][1];
		    g=v[2][1]+v[3][2]+v[1][2];
		    h=v[2][0]+v[3][1];
		    i=v[3][0]+v[3][2]+v[2][1];
		    j=v[2][2]+v[3][1];
		    
		    v[0][1]+=a;
		    v[1][0]+=b;
		    v[1][1]+=c;
		    v[1][2]+=d;
		    v[2][0]+=e;
		    v[2][1]+=f;
		    v[2][2]+=g;
		    v[3][0]+=h;
		    v[3][1]+=i;
		    v[3][2]+=j;
		}
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
		        ans+=v[i][j];
		}
		return ans;
	}
};
