// Last updated: 27/04/2026, 21:51:16


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode * root=new TreeNode(0);
        root=solve(0,nums.size()-1,nums);
        return root;

    }

    TreeNode* solve(int l,int r,vector<int>&nums)
    {
        if(l>r)
        {
            return NULL;
        }
        int m=(l+r)/2;

        
        TreeNode* root = new TreeNode(nums[m]);
        root->left=solve(l,m-1,nums);
        root->right=solve(m+1,r,nums);

        

        return root;
    }


};