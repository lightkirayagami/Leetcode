// Last updated: 27/04/2026, 21:48:34
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
    int sumOfLeftLeaves(TreeNode* root) {
        
        int ans=solve(root,false);
        return ans;
        
    }
    int solve(TreeNode* root,bool onleftleaves)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            if(onleftleaves==true)
            {
                return root->val;
            }
            else return 0;
        }
        
        int a=solve(root->left,true);
        int b=solve(root->right,false);
        return a+b;
        
    }
};