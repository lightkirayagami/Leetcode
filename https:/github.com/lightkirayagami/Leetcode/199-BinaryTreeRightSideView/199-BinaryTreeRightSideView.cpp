// Last updated: 27/04/2026, 21:50:09
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>temp;
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->right!=NULL)
                {
                    q.push(node->right);

                }
                if(node->left!=NULL)
                {
                    q.push(node->left);

                }
            }

            ans.push_back(temp[0]);
        }



        return ans;



        
    }
};