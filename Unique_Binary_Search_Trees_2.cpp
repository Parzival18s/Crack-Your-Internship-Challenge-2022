class Solution {
public:
    vector<TreeNode*> helper(int i, int j)
    {
        vector<TreeNode*>tmp;
        if (i>j)
            return {NULL};
        
        if (i==j)
            return{new TreeNode(i)};
        
        for (int k=i;k<=j;k++)
        {
            vector<TreeNode*>left=helper(i,k-1);
            vector<TreeNode*>right=helper(k+1,j);
            
            for (auto l:left)
            {
                for (auto r:right)
                    tmp.push_back(new TreeNode(k,l,r));
            }
        }
        return tmp;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans=helper(1,n);
        return ans;
    }
};