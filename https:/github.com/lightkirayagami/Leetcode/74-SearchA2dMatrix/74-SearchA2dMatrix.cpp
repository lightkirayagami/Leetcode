// Last updated: 27/04/2026, 21:51:59
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int index = rowindex(matrix, target);
        if (index == -1) {
            return false;
        }

        int ans = bs(matrix[index], target);
        if(ans>-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int rowindex(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n ; i++) {
            if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
                return i;
            }
        }
        return -1;
    }
    
    int bs(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else

            {
                end = mid - 1;
            }
        }
        return -1;
    }
};