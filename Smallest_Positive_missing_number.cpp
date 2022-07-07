class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    { 
        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(arr[i]);
        int ans=1;
        while(s.count(ans))
            ans++;
        return ans;
    } 
};
