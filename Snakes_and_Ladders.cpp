class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_set<int>s;
        unordered_map<int,pair<int,int>>m;
        queue<int>q;
        int dis=0,n=board.size();
        vector<vector<int>>star(n,vector<int>(n,0));
        int light=n*n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                star[i][j]=light;
                light--;
            }
        }
        for(int i=n-1;i>=0;i-=2)
            reverse(star[i].begin(),star[i].end());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                m[star[i][j]]={i,j};
            }
        }
        n*=n;
        q.push(1);
        s.insert(1);
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                int tmp=q.front();
                if(n==tmp)
                    return dis;
                for(int i=tmp+1;i<=min(tmp+6,n);i++)
                {
                    if(!s.count(i))
                    {
                        int f=m[i].first;
                        int g=m[i].second;
                        if(board[f][g]==-1)
                            q.push(i);
                        else
                        {
                            if(!s.count(board[f][g]))
                            {
                                q.push(board[f][g]);
                                if(board[f][g]==-1)
                                    s.insert(board[f][g]);
                            }
                            else
                            {
                                int t=m[board[f][g]].first;
                                int u=m[board[f][g]].second;
                                if(board[t][u]!=-1)
                                    q.push(board[f][g]);
                            }
                        }
                        s.insert(i);
                    }
                }
                q.pop();
            }
            dis++;
        }
        return -1;
    }
};