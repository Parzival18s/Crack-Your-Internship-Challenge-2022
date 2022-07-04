class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &tmp,int target,int sum,vector<int> &candidates,int in,int n)
    {
        if(target==sum)
        {
            ans.push_back(tmp);
            return;
        }
        else if(sum>target)
            return;
        
        for(int i=in;i<n;i++)
        {
            if(i!=in && candidates[i]==candidates[i-1])
                continue;
            sum+=candidates[i];
            tmp.push_back(candidates[i]);
            helper(tmp,target,sum,candidates,i+1,n);
            sum-=candidates[i];
            tmp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>tmp;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(tmp,target,0,candidates,0,n);
        return ans;
    }
};