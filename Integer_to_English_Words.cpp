class Solution {
public:
    string numberToWords(int num) {
        int x,y;
        string s="";
        string a[]={"",""," derdnuH "," dnasuohT ",""," dnasuohT derdnuH ",
                    " noilliM ","","  noilliM derdnuH "," noilliB "};
        string ones[]={" eniN "," thgiE "," neveS "," xiS "," eviF "," ruoF "," eerhT "," owT "," enO "};
        string tens[]={" yteniN "," ythgiE "," ytneveS "," ytxiS "," ytfiF ",
                       " ytroF "," ytrihT "," ytnewT "," neT "};
        string special[]={" neeteniN "," neethgiE "," neetneveS "," neetxiS "," neetfiF ",
                          " neetruoF "," neetrihT "," evlewT "," nevelE "};
        if(num==0)
        {
            s+="Zero";
            return s;
        }
        x=num%10;
        num/=10;
        y=num%10;
        num/=10;
        if(x==0)
        {
            if(y==0)
                x=0;
            else
                s+=tens[9-y];
        }
        else
        {
            if(y==1)
                s+=special[9-x];
            else if(y==0)
                s+=ones[9-x];
            else
            {
                s+=ones[9-x];
                s+=tens[9-y];
            }
        }
        x=num%10;
        num/=10;
        if(x!=0)
        {
            s+=a[2];
            s+=ones[9-x];
        }
        
        int th=0;
        x=num%10;
        num/=10;
        y=num%10;
        num/=10;
        if(x==0)
        {
            if(y==0)
                x=0;
            else
            {
                s+=a[3];
                s+=tens[9-y];
                th=1;
            }
        }
        else
        {
            if(y==1)
            {
                s+=a[3];
                s+=special[9-x];
                th=1;
            }
            else if(y==0)
            {
                s+=a[3];
                s+=ones[9-x];
                th=1;
            }
            else
            {
                s+=a[3];
                s+=ones[9-x];
                s+=tens[9-y];
                th=1;
            }
        }
        x=num%10;
        num/=10;
        if(x!=0)
        {
            if(th==0)
                s+=a[5];
            else
                s+=a[2];
            s+=ones[9-x];
        }
        int mil=0;
        x=num%10;
        num/=10;
        y=num%10;
        num/=10;
        if(x==0)
        {
            if(y==0)
                x=0;
            else
            {
                s+=a[6];
                s+=tens[9-y];
                mil=1;
            }
        }
        else
        {
            if(y==1)
            {
                s+=a[6];
                s+=special[9-x];
                mil=1;
            }
            else if(y==0)
            {
                s+=a[6];
                s+=ones[9-x];
                mil=1;
            }
            else
            {
                s+=a[6];
                s+=ones[9-x];
                s+=tens[9-y];
                mil=1;
            }
        }
        x=num%10;
        num/=10;
        if(x!=0)
        {
            if(mil==0)
                s+=a[8];
            else
                s+=a[2];
            s+=ones[9-x];
        }
        x=num%10;
        num/=10;
        if(x!=0)
        {
            s+=a[9];
            s+=ones[9-x];
        }
        reverse(s.begin(),s.end());
        int i=0,j=s.size()-1;
        while(s[i]==' ')
            i++;
        while(s[j]==' ')
            j--;
        string ans="";
        for(int k=i;k<=j;k++)
        {
            if(s[k]!=' ')
                ans+=s[k];
            else if(s[k+1]!=' ')
                ans+=s[k];
        }
        return ans;
    }
};