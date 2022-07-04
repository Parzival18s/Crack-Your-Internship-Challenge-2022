class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<int>x(m.size()),f(m.size()),v(m.size());
        int j=0;
        for(auto &i:m)
        {
            x[j]=i.first;
            f[j]=i.second;
            v[j]=x[j]*f[j];
            j++;
        }
        if(m.size()==1)
            return v[0];
        if(m.size()==2)
        {
            if(x[1]-x[0]!=1)
                return v[0]+v[1];
            return max(v[0],v[1]);
        }
        if(x[1]-x[0]!=1)
            v[1]+=v[0];
        for(int i=2;i<m.size();i++)
        {
            if(x[i]-x[i-1]!=1)
            {
                auto it=max_element(v.begin(),v.begin()+i);
                v[i]+=*it;
            }
            else
            {
                auto it=max_element(v.begin(),v.begin()+i-1);
                v[i]+=*it;
            }
        }
        return max(v[m.size()-1],v[m.size()-2]);
    }
};