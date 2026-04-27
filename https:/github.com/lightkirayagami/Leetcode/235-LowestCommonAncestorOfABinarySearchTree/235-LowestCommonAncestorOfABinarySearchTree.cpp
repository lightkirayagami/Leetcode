// Last updated: 27/04/2026, 21:49:33
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

        TreeNode* ans=solve(root,p,q);
        return ans;
        
    }

    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val<root->val))
        {
            return root;
        }

        if(p==root||q==root)
        {
            return root;
        }

        TreeNode* a=NULL;
        TreeNode * b=NULL;

        if(p->val<root->val&&q->val<root->val)
        {
            a=solve(root->left,p,q);
        }
        if(p->val>root->val&&q->val>root->val)
        {
            b=solve(root->right,p,q);
        }
         if(a!=NULL&&b!=NULL)
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