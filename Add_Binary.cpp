class Solution {
public:
    string addBinary(string a, string b) {
        string ans="",big,small;
        if(a.length()>b.length())
        {
            big=a;
            small=b;
        }
        else
        {
            small=a;
            big=b;
        }
        int len=big.length(),c=0;
        int dif=len-small.length();
        len--;
        while((len-dif)>=0)
        {
            if((big[len]-'0') and (small[len-dif]-'0') and (c))
            {
                ans+='1';
                c=1;
            }
            else if(((big[len]-'0') and (small[len-dif]-'0')) or ((big[len]-'0') and (c)) or 
                    ((small[len-dif]-'0') and (c)))
            {
                ans+='0';
                c=1;
            }
            else if((big[len]-'0') or (small[len-dif]-'0') or (c))
            {
                ans+='1';
                c=0;
            }
            else
            {
                ans+='0';
                c=0;
            }
            len--;
        }
        while(len>=0)
        {
            if((big[len]-'0') and (c))
            {
                ans+='0';
                c=1;
            }
            else if((big[len]-'0') or (c))
            {
                ans+='1';
                c=0;
            }
            else
            {
                ans+='0';
                c=0;
            }
            len--;
        }
        if(c)
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};