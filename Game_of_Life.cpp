class Solution {
public:
    int helper(vector<vector<int>>board,int i,int j)
    {
        int a=0,p=board.size(),q=board[0].size();
        if(i+1<p and j+1<q and board[i+1][j+1]==1)
            a++;
        if(i+1<p and j-1>=0 and board[i+1][j-1]==1)
            a++;
        if(i+1<p and board[i+1][j]==1)
            a++;
        if(j+1<q and board[i][j+1]==1)
            a++;
        if(j-1>=0 and board[i][j-1]==1)
            a++;
        if(i-1>=0 and j+1<q and board[i-1][j+1]==1)
            a++;
        if(i-1>=0 and j-1>=0 and board[i-1][j-1]==1)
            a++;
        if(i-1>=0 and board[i-1][j]==1)
            a++;
        return a;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>v(board.size(),vector<int>(board[0].size(),0));
        v=board;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int tmp=helper(board,i,j);
                if(board[i][j]==1)
                {
                    if(tmp<2 or tmp>3)
                        v[i][j]=0;
                    else
                        v[i][j]=1;
                }
                else
                {
                    if(tmp==3)
                        v[i][j]=1;
                    else
                        v[i][j]=0;
                }
            }
        }
        board=v;
    }
};