class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int n=nums.size();
        n/=2;
        TreeNode *root;
        root=new TreeNode(nums[n]);
        vector<int>l,r;
        for(int i=0;i<n;i++)
            l.push_back(nums[i]);
        for(int i=n+1;i<nums.size();i++)
            r.push_back(nums[i]);
        root->left=sortedArrayToBST(l);
        root->right=sortedArrayToBST(r);
        return root;
    }
};