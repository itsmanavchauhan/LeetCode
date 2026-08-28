class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            string op=operations[i];
            if(op=="C"){
                st.pop();
            }
            else if(op=="D"){
                st.push(2*(st.top()));
            }
            else if(op=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.push(first);
                st.push(first+second);
            }
            else{
                st.push(stoi(op));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};