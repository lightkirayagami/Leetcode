// Last updated: 27/04/2026, 21:46:12
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
    int sumRootToLeaf(TreeNode* root) {
        
        string s="";
        vector<string>ans;
        int ans1=0;
         solve(root,"" ,ans,ans1);
        
        //  for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // for(int i=0;i<ans.size();i++)
        // {
        //     ans1=ans1+stoi(ans[i], 0, 2);
        // }
        return ans1;
        
        
    };
    
    void solve(TreeNode* root,string s, vector<string>&ans,int &ans1)
    {
       if(root->left==NULL&&root->right==NULL)
       {
           s=s+to_string(root->val);
           ans1=ans1+stoi(s, 0, 2);
           return;
       }
        if(root->left!=NULL)
        solve(root->left,s+to_string(root->val),ans,ans1);
        if(root->right!=NULL)
        solve(root->right,s+to_string(root->val),ans,ans1);
        return;
    }
};