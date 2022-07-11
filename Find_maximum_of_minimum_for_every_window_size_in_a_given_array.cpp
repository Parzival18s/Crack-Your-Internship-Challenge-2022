class Solution {
public:
    void printMaxOfMin(vector<int>& arr) {
        int n=arr.size();
        vector<int>nll(n,-1),nlr(n,n),ans(n+1,INT_MIN);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[i]<=arr[s.top()])
                s.pop();
            if(!s.empty())
                nll[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and arr[i]<=arr[s.top()])
                s.pop();
            if(!s.empty())
                nlr[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int j=nlr[i]-nll[i]-1;
            ans[j]=max(ans[j],arr[i]);
        }
        for(int i=n-1;i>=1;i--)
            ans[i]=max(ans[i],ans[i+1]);
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<'\t';
        cout<<endl;
    }
};