class NestedIterator {
public:
    queue<int>q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i:nestedList)
            helper(i);
    }
    
    int next() {
        int tmp=q.front();
        q.pop();
        return tmp;
    }
    
    bool hasNext() {
        if(q.empty())
            return false;
        return true;
    }
    
    void helper(NestedInteger x)
    {
        if(x.isInteger())
            q.push(x.getInteger());
        else
        {
            for(auto i:x.getList())
                helper(i);
        }
        return;
    }
};