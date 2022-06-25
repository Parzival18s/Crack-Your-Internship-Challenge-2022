class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        stack<char>tmp;
        int flag=1;
        for(int i=0;i<path.length();i++)
        {
            if(path[i]=='/')
            {
                if(flag==1)
                    tmp.push('/');
                flag=0;
            }
            else if(path[i]=='.')
            {
                if(i+2<path.length() and path[i+1]=='.' and path[i+2]=='/')
                {
                    if(tmp.size()>1)
                        tmp.pop();
                    while(tmp.size()>1 and tmp.top()!='/')
                        tmp.pop();
                    i++;
                }
                else if(i+2==path.length() and path[i+1]=='.')
                {
                    if(tmp.size()>1)
                        tmp.pop();
                    while(tmp.size()>1 and tmp.top()!='/')
                        tmp.pop();
                    i++;
                }
                else if(i+1<path.length() and path[i+1]!='/')
                {
                    while(i<path.size() and path[i]!='/')
                    {
                        tmp.push(path[i]);
                        i++;
                    }
                    flag=1;
                    i--;
                }
            }
            else
            {
                while(i<path.length() and path[i]!='/')
                {
                    tmp.push(path[i]);
                    i++;
                }
                flag=1;
                i--;
            }
        }
        int k=tmp.size()-1;
        while(tmp.size()>1 and tmp.top()=='/')
            tmp.pop();
        while(!tmp.empty())
        {
            ans+=tmp.top();
            tmp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};