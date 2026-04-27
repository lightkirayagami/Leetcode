// Last updated: 27/04/2026, 21:46:17
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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int>v1(3);
        vector<int>v2(3);
        solve(root,x,y,v1,v2,0,new TreeNode(-1));
        if(v1[0]!=v1[1]&&v2[0]==v2[1])
        {
            return true;
        }
        return false;
      
        
        
        
    }
    
    void solve(TreeNode* root,int x,int y,vector<int>&v1,vector<int>&v2,int level,TreeNode*parent)
    {
        if(root==NULL)
        {
            return;
        }
    if(root->val==x)
    {
        v1[0]=(parent->val);
        v2[0]=(level);
    }
    if(root->val==y)
    {
        v1[1]=(parent->val);
        v2[1]=(level);
    }
    solve(root->left,x,y,v1,v2,level+1,root);
        solve(root->right,x,y,v1,v2,level+1,root);
    return;
    }
};