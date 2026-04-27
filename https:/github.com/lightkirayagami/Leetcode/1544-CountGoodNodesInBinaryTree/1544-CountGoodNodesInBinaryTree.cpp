// Last updated: 27/04/2026, 21:45:45
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans=0;
    int goodNodes(TreeNode* root) {

        solve(root,-10001);

        return ans;

        
    }

    void solve(TreeNode* root,int max_so_far)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->val>=max_so_far)
        {
            ans++;
        }

        if(max_so_far>root->val)
        {
            solve(root->left,max_so_far);
            solve(root->right,max_so_far);
        }
        else
        {
            solve(root->left,root->val);
            solve(root->right,root->val);

        }
    }
};