// Last updated: 27/04/2026, 21:51:13
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
    bool hasPathSum(TreeNode* root, int targetSum) {

        bool ans=solve(root,targetSum,0);
        return ans;
        
    }

    bool solve(TreeNode* root,int target,int sum)
    {
        if(root==NULL)
        {
            return false;
        }

        if(root->left==NULL&&root->right==NULL)
        {
            int sum1=sum+root->val;
            if(sum1==target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool a=solve(root->left,target,sum+root->val);
        bool b=solve(root->right,target,sum+root->val);
        return a||b;
    }
};