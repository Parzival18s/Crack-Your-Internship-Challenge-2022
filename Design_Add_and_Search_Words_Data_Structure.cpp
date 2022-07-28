class WordDictionary {
public:
    struct TrieNode{
        struct TrieNode *child[26];
        bool isEnd;
    };
    TrieNode* node;
    WordDictionary() {
        node=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur=node;
        for(int i=0;i<word.size();i++)
        {
            if(cur->child[word[i]-'a']==NULL)
                cur->child[word[i]-'a']=new TrieNode();
            cur=cur->child[word[i]-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word,TrieNode* tmp=NULL) {
        TrieNode* cur,* curr;
        if(tmp==NULL)
            cur=node;
        else
            cur=tmp;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                if(i==word.size()-1)
                {
                    bool ans=false;
                    for(char c='a';c<='z';c++)
                    {
                        if(cur->child[c-'a'])
                        {
                            curr=cur->child[c-'a'];
                            if(curr->isEnd)
                                ans=true;
                        }
                        if(ans)
                            break;
                    }
                    return ans;
                }
                bool ans=false;
                string str=word.substr(i+1,word.size()-i);
                for(char c='a';c<='z';c++)
                {
                    if(cur->child[c-'a'])
                        ans=ans or search(str,cur->child[c-'a']);
                    if(ans)
                        break;
                }
                return ans;
            }
            else if(cur->child[word[i]-'a']==NULL)
                return false;
            cur=cur->child[word[i]-'a'];
        }
        if(cur->isEnd)
            return true;
        return false;
    }
};