class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>m;
        vector<vector<string>>v;
        string tmp;
        for(int i=0;i<strs.size();i++)
        {
            tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(i);
        }
        for(auto &i:m)
        {
            vector<string>u;
            for(int j=0;j<i.second.size();j++)
                u.push_back(strs[i.second[j]]);
            v.push_back(u);
        }
        return v;
    }
};