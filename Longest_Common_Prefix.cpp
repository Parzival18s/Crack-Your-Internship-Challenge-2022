class Solution {
public:
    string helper(string a,string b)
    {
        string tmp="";
        int len=min(a.length(),b.length());
        for(int i=0;i<len;i++)
        {
            if(a[i]==b[i])
                tmp+=a[i];
            else
                return tmp;
        }
        return tmp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            ans=helper(ans,strs[i]);
            if(ans=="")
                break;
        }
        return ans;
    }
};