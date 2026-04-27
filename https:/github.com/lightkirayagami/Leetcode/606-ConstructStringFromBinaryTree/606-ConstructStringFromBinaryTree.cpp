// Last updated: 27/04/2026, 21:47:47
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
    string tree2str(TreeNode* root) {

        string ans=solve(root);
        return ans;
    }

    string solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return "";
        }

        if(root->left==NULL&&root->right==NULL)
        {
            return to_string(root->val);
        }

        if(root->left==NULL&&root->right!=NULL)
        {
            string a=solve(root->right);
            a=to_string(root->val)+string("()") + "(" + a + ")";
            return a;
        }

        if(root->left!=NULL &&root->right==NULL)
        {
            string a=solve(root->left);
            return to_string(root->val)+"("+a+")";
        }

        string s=to_string(root->val);

        string a=solve(root->left);
        string b=solve(root->right);

        return s+"("+a+")"+"("+b+")";


    }
};