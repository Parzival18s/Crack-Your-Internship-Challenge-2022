#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    long long ans=INT_MAX,i=0;
    sort(a.begin(),a.end());
    while(i+m-1<n)
    {
        ans=min(ans,a[i+m-1]-a[i]);
        i++;
    }
    return ans;
    }   
};

//Problem was solved on GeeksforGeeks so the main function is their's, not mine.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}