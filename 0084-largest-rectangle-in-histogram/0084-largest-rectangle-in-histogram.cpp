class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int element;
        int maxi=INT_MIN;
        int nse;
        int pse;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                element=heights[st.top()];
                st.pop();
                nse=i;
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top();
                }
                maxarea=element*(nse-pse-1);
                maxi=max(maxarea,maxi);
            }
            st.push(i);
        }
            
        while(!st.empty()){
            nse=n;
            element=heights[st.top()];
            st.pop();
            if(st.empty()){
                pse=-1;
            }
            else{
                pse=st.top();
            }
            maxarea=element*(nse-pse-1);
            maxi=max(maxarea,maxi);

        }
        return maxi;
    }
};