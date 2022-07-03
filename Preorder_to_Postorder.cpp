class Solution{
public:
    Node* helper(int arr[],int i,int j)
    {
        if(i>j)
            return NULL;
        Node* root=newNode(arr[i]);
        int k=i+1;
        while(arr[k]<arr[i] && k<=j)
            k++;
        root->left=helper(arr,i+1,k-1);
        root->right=helper(arr,k,j);
        return root;
    }

    Node* post_order(int pre[], int n)
    {
        if(n==0)
            return NULL;
        return helper(pre,0,n-1);
    }
};