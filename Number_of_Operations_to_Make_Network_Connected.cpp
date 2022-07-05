class Solution {
public:
    unordered_map<int,int>m;
    int helper(int a)
    {
        if(m[a]==a)
            return a;
        return m[a]=helper(m[a]);
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        for(int i=0;i<n;i++)
            m[i]=i;
        int ans=0;
        if(c.size()<n-1)
            return -1;
        int red=0;
        for(int i=0;i<c.size();i++)
        {
            int a=helper(c[i][0]);
            int b=helper(c[i][1]);
            if(a==b)
                red++;
            m[b]=a;
        }
        if(c.size()==n-1)
            return red;
        unordered_set<int>s;
        for(auto &i:m)
        {
            m[i.first]=helper(i.second);
            s.insert(i.second);
        }
        return s.size()-1;
    }
};