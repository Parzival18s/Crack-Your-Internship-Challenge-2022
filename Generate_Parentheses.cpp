class Solution {
public:
    void helper(vector<string>& v,int l,int r,string str)
    {
        if((l<0) or (r<0))
            return;
        if(r<l)
            return;
        if((l==0) and (r==0))
            v.push_back(str);
        helper(v,l-1,r,str+'(');
        helper(v,l,r-1,str+')');
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string str="";
        helper(v,n,n,str);
        return v;
    }
};