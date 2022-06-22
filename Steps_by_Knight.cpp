class Solution 
{
    public:
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    int ans=0,c,flag;
	    if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1])
	        return 0;
	    vector<vector<int>>check(N+1,vector<int>(N+1,-1));
	    while(1)
	    {
	        int tmp=q.size();
	        flag=0;
	        c=0;
	        for(int i=0;i<tmp;i++)
	        {
	            int a=q.front().first;
	            int b=q.front().second;
	            check[a][b]=1;
	            if(a-2>0 and b-1>0 and check[a-2][b-1]==-1)
	            {
	                q.push({a-2,b-1});
	                c++;
	                check[a-2][b-1]=1;
	                if((a-2)==TargetPos[0] and (b-1)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a-2>0 and b+1<=N and check[a-2][b+1]==-1)
	            {
	                q.push({a-2,b+1});
	                c++;
	                check[a-2][b+1]=1;
	                if((a-2)==TargetPos[0] and (b+1)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a-1>0 and b-2>0 and check[a-1][b-2]==-1)
	            {
	                check[a-1][b-2]=1;
	                q.push({a-1,b-2});
	                c++;
	                if((a-1)==TargetPos[0] and (b-2)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a-1>0 and b+2<=N and check[a-1][b+2]==-1)
	            {
	                check[a-1][b+2]=1;
	                q.push({a-1,b+2});
	                c++;
	                if((a-1)==TargetPos[0] and (b+2)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a+2<=N and b-1>0 and check[a+2][b-1]==-1)
	            {
	                check[a+2][b-1]=1;
	                q.push({a+2,b-1});
	                c++;
	                if((a+2)==TargetPos[0] and (b-1)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a+2<=N and b+1<=N and check[a+2][b+1]==-1)
	            {
	                check[a+2][b+1]=1;
	                q.push({a+2,b+1});
	                c++;
	                if((a+2)==TargetPos[0] and (b+1)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a+1<=N and b-2>0 and check[a+1][b-2]==-1)
	            {
	                check[a+1][b-2]=1;
	                q.push({a+1,b-2});
	                c++;
	                if((a+1)==TargetPos[0] and (b-2)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            if(a+1<=N and b+2<=N and check[a+1][b+2]==-1)
	            {
	                check[a+1][b+2]=1;
	                q.push({a+1,b+2});
	                c++;
	                if((a+1)==TargetPos[0] and (b+2)==TargetPos[1])
	                {
	                    flag=1;
	                    break;
	                }
	            }
	            q.pop();
	        }
	        ans++;
	        if(flag==1)
	            break;
	        if(c==0)
	            break;
	    }
	    if(flag==1)
	        return ans;
	    return -1;
	}
};