// Last updated: 27/04/2026, 21:46:41
class StockSpanner {
public:
 stack<pair<int,int> > st;
    StockSpanner() {
        stack<pair<int,int> > st;
    }
    
    int next(int price) {

        int span=1;
        while(!st.empty()&&st.top().first<=price)
        {
            span=span+st.top().second;
            st.pop();
        }

        st.push({price,span});
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */