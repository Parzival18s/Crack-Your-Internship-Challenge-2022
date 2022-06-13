class Solution {
public:
    bool helper(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d,float k,float n)
    {
        float p,q,r;
        p=sqrt(pow(b[1]-a[1],2) + pow(b[0]-a[0],2));
        q=sqrt(pow(c[1]-a[1],2) + pow(c[0]-a[0],2));
        r=sqrt(pow(d[1]-a[1],2) + pow(d[0]-a[0],2));
        if((p==0) or (q==0) or (r==0))
            return false;
        if((p==k and q==k and r==n) or (q==k and r==k and p==n) or (p==k and r==k and q==n))
            return true;
        return false;
        
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float k,n;
        vector<float>f;
        f.push_back(sqrt(pow(p2[0]-p1[0],2) + pow(p2[1]-p1[1],2)));
        f.push_back(sqrt(pow(p3[0]-p1[0],2) + pow(p3[1]-p1[1],2)));
        f.push_back(sqrt(pow(p4[0]-p1[0],2) + pow(p4[1]-p1[1],2)));
        sort(f.begin(),f.end());
        k=f[0];
        n=f[2];
        return helper(p1,p2,p3,p4,k,n) and helper(p2,p1,p3,p4,k,n) and 
               helper(p3,p1,p2,p4,k,n) and helper(p4,p1,p2,p3,k,n);
    }
};