class Solution {
public:
    int res[601][101][101];
    int helper(vector<pair<int,int>>& v,int i,int m,int n)
    {    
        if(i==v.size())
            return 0;
        if(res[i][m][n]!=-1)
            return res[i][m][n];
        int tmp=helper(v,i+1,m,n);
        if(m>=v[i].first and n>=v[i].second)
            tmp=max(tmp,1+helper(v,i+1,m-v[i].first,n-v[i].second));
        return res[i][m][n]=tmp;
    }
    int findMaxForm(vector<string>& strs, int m, int n){
        memset(res,-1,sizeof(res));
        vector<pair<int,int>> v(strs.size(),{0,0});
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                    v[i].first++;
                else
                    v[i].second++;
            }
        }
        return helper(v,0,m,n);
    }
};