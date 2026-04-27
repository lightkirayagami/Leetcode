// Last updated: 27/04/2026, 21:51:23
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while (size--) {

                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left != NULL) {
                    q.push(node->left);
                    // temp.push_back(node->val);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    // temp.push_back(node->val);
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};