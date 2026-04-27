// Last updated: 27/04/2026, 21:49:32
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* temp=solve(root,p,q);
        return temp;
        
    }

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root==p||root==q)
        {
            return root;
        }


        TreeNode* a=solve(root->left,p,q);
        TreeNode *b=solve(root->right,p,q);

        if(a!=NULL&b!=NULL)
        {
            return root;
        }

        if(a!=NULL&&b==NULL)
        {
            return a;
        }
        return b;
    }
};