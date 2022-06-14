class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>v(n,0);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while((!(s.empty())) and (temp[s.top()]<temp[i]))
            {
                v[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
};