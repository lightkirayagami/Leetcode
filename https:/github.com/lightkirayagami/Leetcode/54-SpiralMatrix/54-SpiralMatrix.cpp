// Last updated: 27/04/2026, 21:52:24
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {

            for (int j = left; j <= right; j++) { // if top==bottom no problem
                ans.push_back(matrix[top][j]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]); // if right==left no problem
            }
            right--;
            if (bottom - top != -1)
                 // there is a possibilty top=2 and bottom =1 sp bad record we
                  // need to skip
                {
                    for (int j = right; j >= left; j--) {
                        ans.push_back(matrix[bottom][j]);
                    }

                    bottom--;
                }
            if (right - left != -1) // there is a possibilty left=2 and right =1
                                    // sp bad record we need to skip
            {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }

                left++;
            }
        }
        return ans;
    }
};