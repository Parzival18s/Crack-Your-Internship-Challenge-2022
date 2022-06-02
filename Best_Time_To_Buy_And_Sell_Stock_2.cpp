class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,bp=prices[0],e=1;
        while(e<prices.size())
        {
            if(bp>prices[e])
            {
                bp=prices[e];
            }
            else
            {
                ans+=prices[e]-bp;
                bp=prices[e];
            }
            e++;
        }
        return ans;
    }
};