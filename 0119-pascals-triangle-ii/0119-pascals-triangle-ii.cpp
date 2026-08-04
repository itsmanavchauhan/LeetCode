class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long res = 1;
        ans.push_back(1);
        for (int col=1; col<=rowIndex; col++) {
            res = res*(rowIndex -col + 1);
            res = res/col;
            ans.push_back(res);
        }
        return ans;
    }
};