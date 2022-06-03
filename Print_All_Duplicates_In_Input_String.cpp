class Solution {
public:
    void printDuplicates(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        cout<<"Duplicates:";
        for(auto &i:m)
        {
            if(i.second>1)
                cout<<i.first<<'\t';
        }
        cout<<endl;
    }
};