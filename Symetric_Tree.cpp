class Solution {
public:
    bool compare(TreeNode* r1,TreeNode* r2)
    {
        if((!(r1)) and (!(r2)))
            return true;
        if((!(r1)) or (!(r2)))
            return false;
        if((r1->val)!=(r2->val))
            return false;
        if( ( (!(r1->left)) and (!(r2->right)) or ((r1->left) and (r2->right))   ) and
            ( (!(r1->right)) and (!(r2->left)) or ((r1->right) and (r2->left))   ) )
        {
            if(r1->left)
            {
                if((r1->left->val)!=(r2->right->val))
                    return false;
            }
            if(r1->right)
            {
                if((r1->right->val)!=(r2->left->val))
                    return false;
            }
            return (compare(r1->right,r2->left) and compare(r1->left,r2->right));
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return compare(root->left,root->right);
    }
};