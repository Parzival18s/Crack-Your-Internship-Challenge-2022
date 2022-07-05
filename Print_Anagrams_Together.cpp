class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>>ans;
        unordered_map<int,vector<string>>m;
        for(int i=0;i<string_list.size();i++)
        {
            int tmp=string_list[i].size();
            m[tmp].push_back(string_list[i]);
        }
        for(auto &i:m)
        {
            unordered_set<int>s;
            while(s.size()<i.second.size())
            {
                vector<string>v;
                string theta;
                int cnt=0;
                for(int j=0;j<i.second.size();j++)
                {
                    if(!s.count(j))
                    {
                        cnt=j;
                        theta=i.second[j];
                        break;
                    }
                }
                s.insert(cnt);
                v.push_back(theta);
                sort(theta.begin(),theta.end());
                for(int j=0;j<i.second.size();j++)
                {
                    if(!s.count(j))
                    {
                        string gamma=i.second[j];
                        sort(gamma.begin(),gamma.end());
                        if(gamma==theta)
                        {
                            v.push_back(i.second[j]);
                            s.insert(j);
                        }
                    }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};