// Last updated: 27/04/2026, 21:47:50
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        bool ans=false;
        solve(root,subRoot,ans);
        return ans;
        
    }

    void solve(TreeNode* root,TreeNode* sroot,bool &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(ans==true)
        {
            return;
        }
         if(root->val==sroot->val)
        {
            bool temp=isSameTree(root,sroot);
            if(temp==true)
            {
                ans=true;
            }

        }

        solve(root->left,sroot,ans);
        solve(root->right,sroot,ans);

       
        return;
    }

    bool isSameTree(TreeNode* root,TreeNode* sroot)
    {
       
        if((root==NULL&&sroot!=NULL)|| (root!=NULL&&sroot==NULL))
        {
            return false;
        }
         if(root==NULL&&sroot==NULL)
        {
            return true;
        }

        bool a =isSameTree(root->left,sroot->left);
        
        bool b=isSameTree(root->right,sroot->right);
        
        bool c=false;
        if(root->val==sroot->val)
        {
            c=true;
        }

        return a&&b&&c;


    }


};