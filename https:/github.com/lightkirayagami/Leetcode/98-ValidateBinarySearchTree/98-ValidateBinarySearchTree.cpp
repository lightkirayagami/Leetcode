// Last updated: 27/04/2026, 21:51:28
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
    bool isValidBST(TreeNode* root) {

        bool ans=true;

        solve(root ,LLONG_MIN,LLONG_MAX,ans);
        return ans;
        
    }

    void solve(TreeNode* root,long long left,long long right,bool& ans)
    {


        if(root==NULL)
        {
            return;
        }
        

        if(root->val<=left||root->val>=right)
        {
            ans=false;
        }

        solve(root->left,left,root->val,ans);
        solve(root->right,root->val,right,ans);
        return;
       
    }
};