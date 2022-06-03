class Solution {
public:
    bool helper(string s,int i,int j,int f)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(f==0)
                    return false;
                return helper(s,i+1,j,0) or helper(s,i,j-1,0);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return helper(s,0,s.length()-1,1);
    }
};