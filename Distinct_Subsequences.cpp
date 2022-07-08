class Solution {
public:
    int arr[1005][1005];
    int helper(string s,string t,int i,int j)
    {
        if(arr[i][j]!=-1)
            return arr[i][j];
        if(j==t.size())
            return arr[i][j]=1;
        if(i==s.size())
            return arr[i][j]=0;
        if(s[i]!=t[j])
            return arr[i][j]=helper(s,t,i+1,j);
        return arr[i][j]=helper(s,t,i+1,j+1)+helper(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        memset(arr,-1,sizeof(arr));
        return helper(s,t,0,0);
    }
};