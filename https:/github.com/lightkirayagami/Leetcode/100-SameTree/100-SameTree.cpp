// Last updated: 27/04/2026, 21:51:26
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { return solve(p, q); }

    bool solve(TreeNode* p, TreeNode* q) {
        if (p == NULL && q != NULL || q == NULL && p != NULL) {
            return false;
        }
        if (p == NULL && q == NULL) {
            return true;
        }

        bool a = solve(p->left, q->left);
        bool b = solve(p->right, q->right);

        bool c = false;

        if (p->val == q->val) {
            c = true;
        }
        return a & b & c;
    }
};