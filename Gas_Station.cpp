class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g=0,c=0,ans=0,l=0,r=0;
        for(int i=0;i<gas.size();i++)
        {
            g+=gas[i];
            c+=cost[i];
            l+=gas[i];
            r+=cost[i];
            if(l<r)
            {
                l=0;
                r=0;
                ans=i+1;
            }
        }
        if(g<c)
            return -1;
        return ans;
    }
};