class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l1 = 0, r1 = m - 1;
        int tg_row = -1;
        while(l1 <= r1) {
            int mid1 = l1 + (r1 - l1) / 2;
            if (matrix[mid1][n - 1] < target) {
                l1 = mid1 + 1;
            }
            else if (matrix[mid1][0] > target) {
                r1 = mid1 - 1;
            }
            else {
                tg_row = mid1;
                break;
            }
        }

        if (tg_row == -1) return false;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[tg_row][mid] < target) {
                l = mid + 1;
            }
            else if (matrix[tg_row][mid] > target) {
                r = mid - 1;
            }
            else return true;
        }

        return false;
    }
};
