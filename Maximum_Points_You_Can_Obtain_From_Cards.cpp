class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0,n,tmp=0;
        n=cardPoints.size();
        if(k>=n)
        {
            for(int i=0;i<n;i++)
                ans+=cardPoints[i];
        }
        else
        {
            int i,j=n-1;
            for(i=0;i<k;i++)
                ans+=cardPoints[i];
            tmp=ans;
            i--;
            for(int p=0;p<k;p++)
            {
                tmp-=cardPoints[i];
                tmp+=cardPoints[j];
                i--;
                j--;
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};