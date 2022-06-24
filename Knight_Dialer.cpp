class Solution {
public:
    int m=1e9 +7;
    int knightDialer(int n) {
        int p;
        vector<vector<long long>>v(4,vector<long long>(3,1));
		v[0][0]=0;
		v[0][2]=0;
		n--;
		long long a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
        int ans=0;
		while(n--)
		{
		    a=v[2][0]+v[2][2];
		    b=v[3][1]+v[2][2];
		    c=v[3][0]+v[3][2];
		    d=v[2][0]+v[3][1];
		    e=v[0][1]+v[3][2]+v[1][2];
		    f=0;
		    g=v[0][1]+v[1][0]+v[3][0];
		    h=v[1][1]+v[2][2];
		    i=v[1][0]+v[1][2];
		    j=v[2][0]+v[1][1];
		    
		    v[0][1]=a;
            v[0][1]%=m;
		    v[1][0]=b;
            v[1][0]%=m;
		    v[1][1]=c;
            v[1][1]%=m;
		    v[1][2]=d;
            v[1][2]%=m;
		    v[2][0]=e;
            v[2][0]%=m;
		    v[2][1]=f;
            v[2][1]%=m;
		    v[2][2]=g;
            v[2][2]%=m;
		    v[3][0]=h;
            v[3][0]%=m;
		    v[3][1]=i;
            v[3][1]%=m;
		    v[3][2]=j;
            v[3][2]%=m;
		}
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
            {
                ans+=v[i][j];
                ans%=m;
            }
		}
		return ans;
    }
};