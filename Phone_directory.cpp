class Solution{
public:
struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
};
TrieNode* root=new TrieNode();
void insert(string s)
{
    TrieNode* ptr=root;
    for(int i=0;i<s.size();i++)
    {
        if(!(ptr->child[s[i]-'a']))
            ptr->child[s[i]-'a']=new TrieNode();
        ptr=ptr->child[s[i]-'a'];
    }
    ptr->isEnd=true;
}
TrieNode* prefix(string s)
{
    TrieNode* ptr=root;
    for(int i=0;i<s.size();i++)
    {
        if(!(ptr->child[s[i]-'a']))
            return NULL;
        ptr=ptr->child[s[i]-'a'];
    }
    return ptr;
}
void print(TrieNode* ptr,string s,vector<string>& v)
{
    if(!ptr)
        return;
    if(ptr->isEnd)
        v.push_back(s);
    for(char c='a';c<='z';c++)
    {
        if(ptr->child[c-'a'])
            print(ptr->child[c-'a'],s+c,v);
    }
    return;
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        for(int i=0;i<n;i++)
            insert(contact[i]);
        TrieNode* ptr;
        string tmp;
        vector<vector<string>>ans;
        for(int i=1;i<=s.size();i++)
        {
            tmp=s.substr(0,i);
            ptr=prefix(tmp);
            vector<string>vec;
            print(ptr,tmp,vec);
            if(vec.size()==0)
                vec.push_back("0");
            ans.push_back(vec);
        }
        return ans;
    }
};