class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        string s="";
        int cnt=0;
        for(int i=0;i<str.size();i++)
        {
            m[str[i]]++;
            cnt=max(cnt,m[str[i]]);
        }
        if(cnt>(str.size()+1)/2)
            return s;
        for(auto &i:m)
            pq.push({i.second,i.first});
        while(!pq.empty())
        {
            pair<int,char>a,b;
            a=pq.top();
            pq.pop();
            if(pq.empty())
            {
                s+=a.second;
            }
            else
            {
                b=pq.top();
                pq.pop();
                if(s.size()==0)
                {
                    s+=a.second;
                    s+=b.second;
                    a.first--;
                    b.first--;
                    if(a.first>0)
                        pq.push(a);
                    if(b.first>0)
                        pq.push(b);
                }
                else
                {
                    if(s[s.size()-1]==a.second)
                    {
                        s+=b.second;
                        s+=a.second;
                        a.first--;
                        b.first--;
                        if(a.first>0)
                            pq.push(a);
                        if(b.first>0)
                            pq.push(b);
                    }
                    else
                    {
                        s+=a.second;
                        s+=b.second;
                        a.first--;
                        b.first--;
                        if(a.first>0)
                            pq.push(a);
                        if(b.first>0)
                            pq.push(b);
                    }
                }
            }
        }
        return s;
    }
};