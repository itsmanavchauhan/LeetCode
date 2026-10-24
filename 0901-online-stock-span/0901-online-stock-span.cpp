class StockSpanner {
public:
    stack<int> st;
    vector<int> price;
    int ind = 0;
    StockSpanner() {
    }
    int next(int p) {
        price.push_back(p);
        while(!st.empty() && price[st.top()] <= p) {
            st.pop();
        }
        int ans;
        if(st.empty()) {
            ans = ind + 1;
        }
        else {
            ans = ind - st.top();
        }
        st.push(ind);
        ind++;

        return ans;
    }
};