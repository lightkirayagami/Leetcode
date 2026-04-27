// Last updated: 27/04/2026, 21:49:24
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s="";
        solve(root,ans,"" + to_string(root->val));
        return ans;
        
    }
    
    void solve(TreeNode* root,vector<string>&ans,string s)
    {
        if(root->left==NULL&&root->right==NULL)
        {
           
            
            ans.push_back(s);
            
          return ;
        }
        
        
       if(root->left!=NULL)
       {
           solve(root->left,ans,s +"->" +to_string(root->left->val));
       }
         if(root->right!=NULL)
       {
           solve(root->right,ans,s +"->" +to_string(root->right->val));
       }
        return ;
    }
        
    
};