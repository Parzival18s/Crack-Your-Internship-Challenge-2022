class StockSpanner {
public:
    stack<pair<int,int>>s;
    int i=-1;
    StockSpanner() {
        s.push({INT_MAX,-1});
    }
    
    int next(int price) {
        while(price>=s.top().first)
            s.pop();
        i++;
        int tmp=s.top().second;
        s.push({price,i});
        return i-tmp;
    }
};