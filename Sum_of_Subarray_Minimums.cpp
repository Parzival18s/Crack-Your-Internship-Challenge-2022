class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),ans=0;
        vector<int>left(n,-1),right(n,n);
        int m=1e9;
        m+=7;
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[i]<arr[s.top()])
                s.pop();
            if(!s.empty())
                left[i]=i-s.top();
            else
                left[i]=i+1;
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and arr[i]<=arr[s.top()])
                s.pop();
            if(!s.empty())
                right[i]=s.top()-i;
            else
                right[i]=n-i;
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            long long tmp=(right[i]*left[i])%m;
            tmp=(tmp*arr[i])%m;
            ans=(ans+tmp)%m;
        }
        return ans;
    }
};