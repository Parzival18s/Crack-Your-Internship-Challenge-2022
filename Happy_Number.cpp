class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        unordered_set<int>s;
        s.insert(n);
        int tmp=0,f=0;
        while(n>0)
        {
            f=n%10;
            tmp+=f*f;
            n/=10;
        }
        if(s.count(tmp))
            return false;
        s.insert(tmp);
        if(tmp==1)
            return true;
        while(1)
        {
            n=tmp;
            tmp=0;
            while(n>0)
            {
                f=n%10;
                tmp+=f*f;
                n/=10;
            }
            if(s.count(tmp))
                return false;
            s.insert(tmp);
            if(tmp==1)
                return true;
        }
    }
};