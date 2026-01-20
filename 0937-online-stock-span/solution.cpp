class StockSpanner {
public:
stack<pair<int,int>> stock;
    StockSpanner() {  
    }
    
    int next(int price) {
        int count=1;
        if(!stock.empty()){
            while(!stock.empty() && stock.top().second<=price){
                count+=stock.top().first;
                stock.pop();
            }
        }
        stock.push({count,price});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
