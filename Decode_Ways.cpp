class Solution {
public:
    int v[100];
    int helper(string s,int in)
    {
        if(in==-1)
            return 1;
        if(v[in]!=-1)
            return v[in];
        if(in==0)
            return v[in]=helper(s,in-1);
        int x,y;
        x=s[in-1]-'0';
        y=s[in]-'0';
        x*=10;
        x+=y;
        if(y==0)
            return v[in]=helper(s,in-2);
        if(x>26 or x<10)
            return v[in]=helper(s,in-1);
        return v[in]=helper(s,in-1)+helper(s,in-2);
    }
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0' and (s[i-1]!='1' and s[i-1]!='2'))
                return 0;
        }
        memset(v,-1,sizeof(v));
        int ans=helper(s,s.size()-1);
        return ans;
    }
};