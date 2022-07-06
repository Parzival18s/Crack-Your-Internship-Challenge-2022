class Solution {
public:
    string permute(int a[],int b[],int k) {
        int n;
        n=sizeof(a)/sizeof(a[0]);
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        for(int i=0;i<n;i++)
        {
            if((a[i]+b[i])<k)
                return "No";
        }
        return "Yes";
    }
};
