class Solution {
public:
    bool helper(vector<vector<char>>&v,int i,int j,string word,int pos)
    {
        if(pos==word.size())
            return true;
        if((i<0) or (i==v.size()) or (j<0) or (j==v[0].size()) or v[i][j]!=word[pos])
           return false;
        v[i][j]='.';
        bool res;
        res=helper(v,i+1,j,word,pos+1) or helper(v,i-1,j,word,pos+1) or 
            helper(v,i,j+1,word,pos+1) or helper(v,i,j-1,word,pos+1);
        v[i][j]=word[pos];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()>board.size()*board[0].size())
            return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(helper(board,i,j,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};