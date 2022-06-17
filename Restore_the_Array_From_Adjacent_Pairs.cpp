class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int,int>cnt;
        unordered_map<int,vector<int>>ed;
        unordered_set<int>check;
        for(int i=0;i<pairs.size();i++)
        {
            cnt[pairs[i][0]]++;
            cnt[pairs[i][1]]++;
            ed[pairs[i][0]].push_back(pairs[i][1]);
            ed[pairs[i][1]].push_back(pairs[i][0]);
        }
        int st;
        for(auto &i:cnt)
        {
            if(i.second==1)
            {
                st=i.first;
                break;
            }
        }
        vector<int>ans;
        ans.push_back(st);
        check.insert(st);
        for(int i=0;i<pairs.size();i++)
        {
            int tmp=ans[ans.size()-1];
            if(!(check.count(ed[tmp][0])))
            {
                ans.push_back(ed[tmp][0]);
                check.insert(ed[tmp][0]);
            }
            else
            {
                ans.push_back(ed[tmp][1]);
                check.insert(ed[tmp][1]);
            }
        }
        return ans;
    }
};