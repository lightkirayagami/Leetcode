// Last updated: 27/04/2026, 21:48:05
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
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        TreeNode* ansNode=NULL;

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                ansNode=node;
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
            }
        }

        return ansNode->val;
        
    }
};