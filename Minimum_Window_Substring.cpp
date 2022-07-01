class Solution {
public:
    string minWindow(string s, string t) {
        unordered_set<char>u;
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++)
        {
            u.insert(t[i]);
            m[t[i]]++;
        }
        int count=t.size(),ans=INT_MAX,i=0,j=0;
        string str="";
        while(j<s.size())
        {
            if(u.count(s[j]))
            {
                if(m[s[j]]>0)
                    count--;
                m[s[j]]--;
            }
            if(count==0)
            {
                while(!u.count(s[i]) or count==0)
                {
                    if(u.count(s[i]))
                    {
                        m[s[i]]++;
                        if(m[s[i]]>0)
                        {
                            count++;
                            break;
                        }
                    }
                    i++;
                }
                m[s[i]]--;
                count--;
                if(ans>(j-i+1))
                {
                    string tmp="";
                    for(int k=i;k<=j;k++)
                        tmp+=s[k];
                    str=tmp;
                    ans=j-i+1;
                }
            }
            j++;
        }
        return str;
    }
};