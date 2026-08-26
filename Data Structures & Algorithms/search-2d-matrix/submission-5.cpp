class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int l = 0, r = (ROWS * COLS) - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / COLS, col = mid % COLS;
            int midVal = matrix[row][col];
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
