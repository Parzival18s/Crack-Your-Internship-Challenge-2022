class Solution {
public:
    string helper(int tmp,char big,char mid,char small)
    {
        string ans="";
        if(tmp==9)
        {
            ans+=small;
            ans+=big;
            tmp=0;
        }
        else if(tmp>=5)
        {
            tmp-=5;
            ans+=mid;
        }
        else if(tmp==4)
        {
            ans+=small;
            ans+=mid;
            tmp=0;
        }
        for(int i=0;i<tmp;i++)
            ans+=small;
        return ans;
    }
    string intToRoman(int num) {
        string ans="";
        int  tmp;
        while(num>0)
        {
            if(num>=1000)
            {
                tmp=num/1000;
                num=num%1000;
                for(int i=0;i<tmp;i++)
                    ans+="M";
            }
            else if(num>=100)
            {
                tmp=num/100;
                num%=100;
                ans+=helper(tmp,'M','D','C');
            }
            else if(num>=10)
            {
                tmp=num/10;
                num%=10;
                ans+=helper(tmp,'C','L','X');
            }
            else
            {
                tmp=num;
                num=0;
                ans+=helper(tmp,'X','V','I');
            }
        }
        return ans;
    }
};