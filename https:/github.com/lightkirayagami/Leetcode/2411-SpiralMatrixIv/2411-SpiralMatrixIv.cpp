// Last updated: 27/04/2026, 21:44:52
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> mat(m, vector<int>(n, -1));  // Initialize matrix with -1
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;
        
        while (curr) {
            // Fill top row
            for (int i = left; i <= right && curr; i++) {
                mat[top][i] = curr->val;
                curr = curr->next;
            }
            top++;
            
            // Fill right column
            for (int i = top; i <= bottom && curr; i++) {
                mat[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            
            // Fill bottom row
            for (int i = right; i >= left && curr; i--) {
                mat[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;
            
            // Fill left column
            for (int i = bottom; i >= top && curr; i--) {
                mat[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        
        return mat;
        
    }
};