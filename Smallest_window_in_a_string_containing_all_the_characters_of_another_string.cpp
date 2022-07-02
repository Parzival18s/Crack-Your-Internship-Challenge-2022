class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        if(p.size()>s.size())
            return "-1";
        
        unordered_map<char,int>m;
        
        for(int i=0;i<p.size();i++)
            m[p[i]]++;
        
        vector<char>t;
        vector<int>index;
        
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]!=0)
            {
                t.push_back(s[i]);
                index.push_back(i);
            }
        }
        
        int count=p.size(),ans=INT_MAX,i=0,j=0;
        string str="";
        while(j<t.size())
        {
            if(m[t[j]]>0)
                count--;
            m[t[j]]--;
            if(count==0)
            {
                while(count==0)
                {
                    m[t[i]]++;
                    if(m[t[i]]>0)
                        count++;
                    else
                        i++;
                }
                m[t[i]]--;
                count--;
                if(ans>(index[j]-index[i]+1))
                {
                    str=s.substr(index[i],index[j]-index[i]+1);
                    ans=index[j]-index[i]+1;
                }
            }
            j++;
        }
        if(str=="")
            str="-1";
        return str;
    }
};