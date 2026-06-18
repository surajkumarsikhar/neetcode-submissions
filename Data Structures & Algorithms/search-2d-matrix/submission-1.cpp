class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix[0].size();
        int rowSize = matrix.size();
        int high = (rowSize * colSize) - 1;
        int low = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid/colSize][mid%colSize] == target){
                return true;
            } else if(matrix[mid/colSize][mid%colSize] > target){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return false;
    }
};
