class Solution {
public:
    int minDeletions(string str) {
        unordered_map<char,int>mp;
        unordered_set<int>s;
        for(int i=0;i<str.size();i++)
            mp[str[i]]++;
        int ans=0;
        for(auto &i:mp)
        {
            if(s.count(i.second))
            {
                int tmp=i.second;
                while(s.count(tmp))
                {
                    ans++;
                    tmp--;
                }
                if(tmp>0)
                    s.insert(tmp);
            }
            else
                s.insert(i.second);
        }
        return ans;
    }
};