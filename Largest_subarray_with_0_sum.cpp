class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>m;
        int ans=0;
        int psum=0;
        for(int i=0;i<n;i++)
        {
            psum+=A[i];
            if(psum==0)
                ans=max(ans,i+1);
            else
            {
                if(m[psum]==0)
                    m[psum]=i+1;
                else
                    ans=max(ans,i-m[psum]+1);
            }
        }
        return ans;
    }
};