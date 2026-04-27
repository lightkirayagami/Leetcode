// Last updated: 27/04/2026, 21:51:18
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>level;  
      queue<TreeNode*>q;
      q.push(root);
        if(root==NULL)
        {
            return level;
        }
        
      while(!q.empty())
      {  
          
          int size=q.size();
          vector<int>ans1;
         
          for(int i=0;i<size;i++)
          {
            TreeNode* root1=q.front();
              q.pop();
            ans1.push_back(root1->val);
            if(root1->left!=NULL)
            q.push(root1->left);
            if(root1->right!=NULL)
            q.push(root1->right);
              
          }
          level.push_back(ans1);
         
      }
        reverse(level.begin(),level.end());
        
        return level;
        
    }
};