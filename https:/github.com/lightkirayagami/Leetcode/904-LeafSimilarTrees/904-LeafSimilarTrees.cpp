// Last updated: 27/04/2026, 21:46:50
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        answer1(root1,root2,ans1);
        answer2(root1,root2,ans2);
     if(ans1==ans2)
     {
         return true;
     }
        else
            return false;
        
    };
    void answer1(TreeNode* root1, TreeNode* root2,  vector<int>&ans1)
    {
        if(root1 == NULL) return;
        
        if(root1->left==NULL && root1->right==NULL)
        {
            ans1.push_back(root1->val);
            return;
        }
        
        answer1(root1->left,root2,ans1);
        answer1(root1->right,root2,ans1);
      
            
    };
    void answer2(TreeNode* root1, TreeNode* root2,  vector<int>&ans2)
        
    {
        if(root2 == NULL) return;
        if(root2->left==NULL&& root2->right==NULL)
        {
            ans2.push_back(root2->val);
            return;
        }
        
        answer2(root1,root2->left,ans2);
        answer2(root1,root2->right,ans2);
      
        
        
        
        
    };
};