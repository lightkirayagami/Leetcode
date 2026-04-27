// Last updated: 27/04/2026, 21:48:17
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root==NULL)
        {
            return root;
        }
        else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==NULL&&root->right==NULL)
            {
                root=NULL;
                return root;
            }
            else if(root->left==NULL)
            {
                
                root=root->right;
                return root;

            }
            else if(root->right==NULL)
            {
                root=root->left;
                return root;
            }
            else
            {
                TreeNode* temp=findMin(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
                return root;
            }
        }
        return root;
        
    }

    TreeNode* findMin(TreeNode* root)
    {
        if(root->left!=NULL)
        {
            root=findMin(root->left);
        }
        else
        {
            return root;
        }
        return root;
    }
};