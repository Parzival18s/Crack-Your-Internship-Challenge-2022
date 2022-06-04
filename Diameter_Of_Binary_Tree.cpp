class Solution {
public:
    int height(TreeNode* root,int& diameter){
        if(root==NULL)
            return 0;
        int left=height(root->left,diameter);
        int right=height(root->right,diameter);
        diameter=max(diameter,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int diameter=0;
        height(root,diameter);
        return diameter;
    }    
};