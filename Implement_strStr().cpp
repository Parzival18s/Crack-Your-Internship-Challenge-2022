class Solution {
public:
    bool helper(string needle,string haystack,int pos,int i)
    {
        if(pos==needle.length())
            return true;
        if(i==haystack.length())
            return false;
        if(needle[pos]!=haystack[i])
            return false;
        return helper(needle,haystack,pos+1,i+1);
    }
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        if(needle.length()>haystack.length())
            return -1;
        int len=needle.length();
        for(int i=0;i<haystack.length();i++)
        {
            if(helper(needle,haystack,0,i))
                return i;
        }
        return -1;
    }
};