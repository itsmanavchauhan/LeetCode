class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //left will be psee
        //right will be nse
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) left[i]=-1;
            else{
                left[i]=st.top();
            }
            st.push(i);
        }

        stack<int>st2;

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            if(st2.empty()) right[i]=n;
            else{
                right[i]=st2.top();
            }
            st2.push(i);

        }


        long long total=0;
        for(int i=0;i<n;i++){
            int leftcount = i-left[i];
            int rightcount = right[i]-i;
            total=(total+ (long long)leftcount*rightcount*arr[i])%1000000007;
        }
        return total;
    }
};