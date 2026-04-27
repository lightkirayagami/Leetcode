// Last updated: 27/04/2026, 21:51:19
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
int idx=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        TreeNode* ans=solve(0,preorder.size()-1,preorder,inorder);
        return ans;
        
        
    }

    TreeNode* solve(int l,int r,vector<int>&preorder,vector<int>inorder)
    {
        if(l>r)
        {
            return NULL;
        }

        TreeNode* node=new TreeNode(preorder[idx]);idx++;
        
        int k=l;

        while (inorder[k] != node->val) k++;
        node->left=solve(l,k-1,preorder,inorder);
        node->right=solve(k+1,r,preorder,inorder);

        return node;


        
    } 
};