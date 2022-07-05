class Solution {
public:
    unordered_map<int,vector<int>>m;
    vector<int>time;
    int helper(int id)
    {
        if(m[id].size()==0)
            return 0;
        int tmp=INT_MIN;
        for(int i=0;i<m[id].size();i++)
            tmp=max(tmp,time[id]+helper(m[id][i]));
        return tmp;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        time=informTime;
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                m[manager[i]].push_back(i);
        }
        return helper(headID);
    }
};