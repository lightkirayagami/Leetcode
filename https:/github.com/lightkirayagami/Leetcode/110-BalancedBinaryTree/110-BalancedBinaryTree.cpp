// Last updated: 27/04/2026, 21:51:14
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
    bool isBalanced(TreeNode* root) {

        int ans=solve(root);
        if(ans==-1)
        {
            return false;
        }
        return true;
        
    }

    int solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }


        int l=solve(root->left);
        int r=solve(root->right);
        if(l==-1)
        {
            return -1;
        }
        if(r==-1)
        {
            return -1;
        }


        if(abs(l-r)>1)
        {
            return -1;
        }

        return 1+max(l,r);
    }

    
};