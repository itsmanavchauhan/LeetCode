class Solution {
public:
    int maxRow(vector<vector<int>>& mat,int col){
        int row = 0;
        for(int i = 1; i < mat.size(); i++){
            if(mat[i][col] > mat[row][col]){
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while(low <= high){
            int mid = low + (high-low)/2;
            int row = maxRow(mat, mid);
            int left = (mid-1 >= 0) ? mat[row][mid-1]: -1;
            int right = (mid+1 < m)? mat[row][mid+1]: -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(left > mat[row][mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};