class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        unordered_set<int>s;
        while(1)
        {
            int flag=0;
            for(int i=0;i<graph.size();i++)
            {
                if(graph[i].size()==0)
                {
                    if(!s.count(i))
                    {
                        s.insert(i);
                        ans.push_back(i);
                        flag++;
                    }
                }
                else
                {
                    if(!s.count(i))
                    {
                        int cnt=0;
                        for(int j=0;j<graph[i].size();j++)
                        {
                            if(!s.count(graph[i][j]))
                            {
                                cnt=1;
                                break;
                            }
                        }
                        if(cnt==0)
                        {
                            s.insert(i);
                            ans.push_back(i);
                            flag++;
                        }
                    }
                }
            }
            if(flag==0)
                break;
        }
        if(ans.size()!=0)
            sort(ans.begin(),ans.end());
        return ans;
    }
};