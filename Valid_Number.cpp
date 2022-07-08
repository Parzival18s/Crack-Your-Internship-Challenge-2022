class Solution {
public:
    int helper1(string s,int i)
    {
        bool flag=false;
        if(s[i]=='+' or s[i]=='-')
            i++;
        if(i==s.size())
            return -1;
        if(!((s[i]>='0' and s[i]<='9') or (s[i]=='.')))
            return -1;
        while(i<s.size() and s[i]>='0' and s[i]<='9')
        {
            flag=true;
            i++;
        }
        if(i==s.size())
            return -1;
        if(s[i]!='.')
            return -1;
        else
            i++;
        if(i==s.size() and !flag)
            return -1;
        if(!flag and !(s[i]>='0' and s[i]<='9'))
            return -1;
        while(i<s.size() and s[i]>='0' and s[i]<='9')
            i++;
        return i;
    }
    int helper2(string s,int i)
    {
        if(s[i]=='+' or s[i]=='-')
            i++;
        if(i==s.size())
            return -1;
        if(!(s[i]>='0' and s[i]<='9'))
            return -1;
        while(i<s.size() and s[i]>='0' and s[i]<='9')
            i++;
        return i;
    }
    bool isNumber(string s) {
        int a,b;
        a=helper1(s,0);
        b=helper2(s,0);
        if(a==-1 and b==-1)
            return false;
        if(a==s.size() or b==s.size())
            return true;
        if(a<b)
            a=b;
        if(s[a]!='e' and s[a]!='E')
            return false;
        a++;
        b=helper2(s,a);
        if(b==s.size())
            return true;
        return false;
    }
};