// Last updated: 27/04/2026, 21:51:11
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>path;
        vector<int>ans;
        solve(root,ans,targetSum,path);
        return path;
        
    }

    void solve(TreeNode* root,vector<int>&ans,int sum,vector<vector<int>>&path)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            sum=sum-root->val;
            
            if(sum==0)
            {
                ans.push_back(root->val);
                path.push_back(ans);
                ans.pop_back();
                return;
            }
            else
            {
                return;
            }
        }

        ans.push_back(root->val);


        solve(root->left,ans,sum-root->val,path);
        solve(root->right,ans,sum-root->val,path);

         ans.pop_back();
    }
};