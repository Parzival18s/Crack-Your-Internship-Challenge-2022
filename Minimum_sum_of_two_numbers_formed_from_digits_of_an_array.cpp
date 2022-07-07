class Solutiom{
public:
    int minSum(vector<int>arr)
    {
        int n=arr.size();
        int p=0,q=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i%2)
            {
                p*=10;
                p+=arr[i];
            }
            else
            {
                q*=10;
                q+=arr[i];
            }
        }
        return p+q;
    }
};