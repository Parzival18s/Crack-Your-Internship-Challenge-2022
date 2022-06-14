class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>s;
        int tmp,a,b;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=="+" or t[i]=="-" or t[i]=="*" or t[i]=="/")
            {
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                if(t[i]=="+")
                    tmp=b+a;
                else if(t[i]=="-")
                    tmp=b-a;
                else if(t[i]=="*")
                    tmp=b*a;
                else
                    tmp=b/a;
                s.push(tmp);
            }
            else
            {
                tmp=stoi(t[i]);
                s.push(tmp);
            }
        }
        return s.top();
    }
};