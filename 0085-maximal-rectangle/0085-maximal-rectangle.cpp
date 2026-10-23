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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> heights(m,0);
        int maxi= 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] =0;
                }
            }
            int area = largestRectangleArea(heights);
            maxi=max(maxi, area);
        }

        return maxi;
    }
};