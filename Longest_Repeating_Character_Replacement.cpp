class Solution {
public:
    int helper(unordered_map<char,int>m)
    {
        int ret=INT_MIN;
        for(auto &i:m)
            ret=max(ret,i.second);
        return ret;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int i=0,j=1,ans=0,cnt,tot;
        m[s[0]]=1;
        cnt=1;
        tot=1;
        while(j<s.size())
        {
            if(cnt==m[s[j]])
            {
                m[s[j]]++;
                tot++;
                cnt++;
            }
            else
            {
                m[s[j]]++;
                tot++;
            }
            while(tot-cnt>k)
            {
                if(m[s[i]]==cnt)
                {
                    tot--;
                    m[s[i]]--;
                    cnt=helper(m);
                    i++;
                }
                else
                {
                    tot--;
                    m[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};