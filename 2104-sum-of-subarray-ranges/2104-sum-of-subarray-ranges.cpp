class Solution {
public:

    long long Subarraymin(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >=nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }

            st.push(i);
        }

        long long total = 0;
        for(int i = 0; i < n; i++){

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            total += (long long)nums[i] * leftCount * rightCount;
        }

        return total;
    }


    long long Subarraymax(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <=nums[i]){
                st.pop();
            }

            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }

            st.push(i);
        }

        long long total = 0;
        for(int i = 0; i < n; i++){
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            total += (long long)nums[i] * leftCount * rightCount;
        }

        return total;
    }


    long long subArrayRanges(vector<int>& nums) {

        long long maximum = Subarraymax(nums);
        long long minimum = Subarraymin(nums);

        return maximum - minimum;
    }
};