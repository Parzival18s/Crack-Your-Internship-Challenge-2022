class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>s;
        for(int i=0;i<num.size();i++)
        {
            while(!s.empty() and s.top()>num[i] and k>0)
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size()==1 and s.top()=='0')
                s.pop();
        }
        while(k>0 and !s.empty())
        {
            k--;
            s.pop();
        }
        if(s.empty())
            return "0";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};