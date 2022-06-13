class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>f,l;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(i==sqrt(n))
                    f.push_back(i);
                else
                {
                    f.push_back(i);
                    l.push_back(n/i);
                }
            }
        }
        int p=f.size(),q=l.size();
        if(k>p+q)
            return -1;
        if(k<=p)
            return f[k-1];
        k-=p;
        reverse(l.begin(),l.end());
        return l[k-1];
    }
};