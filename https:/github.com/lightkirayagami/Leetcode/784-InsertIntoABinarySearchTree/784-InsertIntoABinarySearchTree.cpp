// Last updated: 27/04/2026, 21:47:04
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
        root=new TreeNode(val);
        return root;
        }

        find(root,val);
        return root;
        
    }
void find(TreeNode* &root,int val)
    {
        if(root==NULL)
        {
            root=new TreeNode(val);
            return;
        }

        if(root->val<val)
        {
            find(root->right,val);
        }
        else
        {
            find(root->left,val);
        }
    }
};