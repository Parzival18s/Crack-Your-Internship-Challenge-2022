class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string tmp,num;
        int x;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                tmp="";
                while(st.top()!='[')
                {
                    tmp+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(tmp.begin(),tmp.end());
                num="";
                while(!st.empty() and st.top()>='0' and st.top()<='9')
                {
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                x=stoi(num);
                while(x--)
                {
                    for(int j=0;j<tmp.size();j++)
                        st.push(tmp[j]);
                }
            }
        }
        tmp="";
        while(!st.empty())
        {
            tmp+=st.top();
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};