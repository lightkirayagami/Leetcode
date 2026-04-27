// Last updated: 27/04/2026, 21:49:40
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
    int kthSmallest(TreeNode* root, int k) {

        vector<int>ans;
        solve(root,ans);
        int ans1;
        for(int i=0;i<k;i++)
        {
            ans1=ans[i];
        }
        return ans1;
        
    }

    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
};