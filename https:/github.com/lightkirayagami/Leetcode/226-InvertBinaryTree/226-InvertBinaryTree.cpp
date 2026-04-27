// Last updated: 27/04/2026, 21:49:41
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
    TreeNode* invertTree(TreeNode* root) {
        

        if(root==NULL)
        {
            return root;
        }

        return invert(root);
    }

    TreeNode* invert(TreeNode* root)
    {
        if(root==NULL)
        {
            return root;
        }

        root->left=invert(root->left);
        root->right=invert(root->right);

        swap(root->left,root->right);

        return root;
    }
};