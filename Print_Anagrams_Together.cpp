class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<string_list.size();i++)
        {
            string tmp=string_list[i];
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(string_list[i]);
        }
        for(auto &i:m)
        {
            vector<string>v;
            for(int j=0;j<i.second.size();j++)
                v.push_back(i.second[j]);
            ans.push_back(v);
        }
        return ans;
    }
};
