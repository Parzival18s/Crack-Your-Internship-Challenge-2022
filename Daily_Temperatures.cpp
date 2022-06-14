class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>v;
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(!s.empty() and temp[i]<temp[s.top()])
                v.push_back(s.top()-i);
            else
            {
                while(!s.empty() and temp[i]>=temp[s.top()])
                    s.pop();
                if(s.empty())
                    v.push_back(0);
                else
                    v.push_back(s.top()-i);
            }
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
