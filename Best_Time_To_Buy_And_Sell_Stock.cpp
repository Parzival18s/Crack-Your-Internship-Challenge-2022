class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,bp=prices[0],e=1;
        while(e<prices.size())
        {
            if(prices[e]>bp)
            {
                ans=max(ans,prices[e]-bp);
            }
            else
                bp=prices[e];
            e++;
        }
        return ans;
    }
};