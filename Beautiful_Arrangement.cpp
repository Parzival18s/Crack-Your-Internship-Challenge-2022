class Solution {
public:
    int ans=0;
    void helper(vector<int>v,int in)
    {
        if(in==v.size())
        {
            ans++;
            return;
        }
        int a,b;
        for(int j=in;j<v.size();j++)
        {
            a=v[j]%(in+1);
            b=(in+1)%v[j];
            if(a==0 or b==0)
            {
                swap(v[in],v[j]);
                helper(v,in+1);
                swap(v[in],v[j]);
            }
        }
        return;
    }
    int countArrangement(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++)
            v.push_back(i);
        helper(v,0);
        return ans;
    }
};