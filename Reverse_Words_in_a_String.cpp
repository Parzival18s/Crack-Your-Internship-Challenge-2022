class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=s.size()-1;
        while(s[i]==' ')
            i++;
        while(s[j]==' ')
            j--;
        stack<char>st;
        string ans="";
        while(i<=j)
        {
            while((j>=i) and (s[j]!=' '))
            {
                st.push(s[j]);
                j--;
            }
            while(!(st.empty()))
            {
                ans+=st.top();
                st.pop();
            }
            if(j>i)
            {
                ans+=' ';
                while(s[j]==' ')
                    j--;
            }
        }
        return ans;
    }
};