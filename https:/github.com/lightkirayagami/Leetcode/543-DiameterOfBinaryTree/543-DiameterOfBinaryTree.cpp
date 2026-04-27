// Last updated: 27/04/2026, 21:47:57
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
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==NULL)
        {
            return 0;
        }
        int dia=diameter(root);
        return dia;
        
    }


    int  diameter(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int leftheight=height(root->left);
        int rightheight=height(root->right);

        int d1=diameter(root->left);
        int d2=diameter(root->right);

        int max1=max(d1,d2);
        max1=max(max1,leftheight+rightheight);


        return max1;

    }

    int height(TreeNode* root){
        if(root==NULL)
        {
            return 0;
        }

        int a=height(root->left);
        int b=height(root->right);
        return 1+max(a,b);
    }


};