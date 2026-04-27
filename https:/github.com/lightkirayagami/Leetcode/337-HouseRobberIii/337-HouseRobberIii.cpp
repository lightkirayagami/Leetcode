// Last updated: 27/04/2026, 21:48:58
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
    int rob(TreeNode* root) {

        int ans1 = 0, ans2 = 0;

        unordered_map<TreeNode*, vector<int>> dp;
        ans1 = solve(root, 0,dp);
        ans2 = solve(root, 1,dp);

        return max(ans1, ans2);
    }

   int solve(TreeNode* root, int canbuy, unordered_map<TreeNode*, vector<int> > &dp) {

        if (root == NULL) {
            return 0;
        }

        // if dp exists & calculated for this state
        if (dp.find(root) != dp.end() && dp[root][canbuy] != -1) {
            return dp[root][canbuy];
        }

        // initialize dp for this node if first time
        if (dp.find(root) == dp.end()) {
            dp[root] = vector<int>(2, -1);
        }

        int pick = 0;     
        int notpick = 0;

        if (canbuy == 1) {
            pick = root->val 
                + solve(root->left, 0, dp) 
                + solve(root->right, 0, dp);

            notpick = solve(root->left, 1, dp) 
                    + solve(root->right, 1, dp);
        }
        else {
            notpick = solve(root->left, 1, dp) 
                    + solve(root->right, 1, dp);
        }

        dp[root][canbuy] = max(pick, notpick);
        return dp[root][canbuy];
    }


};