class Solution {
public:
    int Minamount(vector<int> cost,int k) {
        sort(cost.begin(),cost.end());
        int i=0,j=cost.size()-1,ans=0;
        while(i<j)
        {
            ans+=cost[i];
            i++;
            j-=k;
        }
        return ans;
    }
};
