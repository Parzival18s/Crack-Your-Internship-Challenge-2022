class Solution {
public:
    int reverse(int x) {
        if(x==-1*pow(2,31))
            return 0;
        long long a=0,b=1,tmp;
        int q;
        if(x<0)
        {
            b=-1;
            x*=-1;
        }
        while(x>0)
        {
            tmp=x%10;
            if(a+tmp>=pow(2,31))
                return 0;
            a+=tmp;
            if(x>=10)
            {
                if(a*10>=pow(2,31))
                    return 0;
                a*=10;
            }
            x/=10;
        }
        q=a;
        return q*b;
    }
};