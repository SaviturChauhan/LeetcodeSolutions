class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st = 0;
        int end = m*n -1;
        // row  -- >  idx / n 
        // col  -- > idx % n

        while(st <= end ){
            int mid = st + (end-st)/2;
            if(matrix[mid/n][mid%n] > target) end = mid-1;
            else if(matrix[mid/n][mid%n] < target) st = mid+1;
            else return true;
        }
        return false;

    }
};