class RandomizedCollection {
public:
    unordered_map<int,int>m;
    vector<int>v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        m[val]++;
        v.push_back(val);
        if(m[val]>1)
            return false;
        return true;
    }
    
    bool remove(int val) {
        if(m[val]==0)
            return false;
        m[val]--;
        auto it=find(v.begin(),v.end(),val);
        v.erase(it);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};