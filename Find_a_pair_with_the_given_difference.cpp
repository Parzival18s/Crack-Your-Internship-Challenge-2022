class Solution {
public:
    bool findPair(vector<int>arr,int dif){
        int n=arr.size();
        unordered_map<int,int> m;
        for (int i=0;i<n;i++)
        {
            m[arr[i]]++;
            if(dif==0 && m[arr[i]]>1)
            {
                cout<<arr[i]<<'\t'<<arr[i]<<endl;
                return true;
            }
        }
        if (dif==0)
            return false;
        for (int i=0;i<n;i++)
        {
            if (m.find(dif+arr[i])!=m.end())
            {
                cout<<arr[i]<<'\t'<<dif+arr[i]<<endl;
                return true;
            }
        }
        return false;
}
};