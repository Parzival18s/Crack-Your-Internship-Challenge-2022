class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a,int target) {
        map<vector<int>,int>m;
        int n=a.size();
        vector<vector<int>> res;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            long t3=target-a[i];
            for(int j=i+1;j<n;j++)
            {
                long t2=t3-a[j];
                long l=0,r=n-1;
                while(l<i && r>j)
                {
                    long tmp=a[l]+a[r];
                    if(tmp<t2)
                        l++;
                    else if(tmp>t2)
                        r--;
                    else
                    {
                        m[{a[l],a[i],a[j],a[r]}]=1;
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto &c:m)
            res.push_back(c.first);
        return res;
    }
};