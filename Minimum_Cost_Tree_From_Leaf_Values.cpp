class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans=0;
        while(arr.size()>1)
        {
            int x=INT_MAX; 
            int in=-1;
            for(int i=0;i<arr.size()-1;i++)
            {
                int tmp=arr[i]*arr[i+1];
                if(tmp<x)
                {
                    x=tmp;
                    in=i;
                }
            }
            ans+=x;
			arr[in]=max(arr[in],arr[in+1]);
            arr.erase(arr.begin()+in+1);
        }
        return ans;
    }
};