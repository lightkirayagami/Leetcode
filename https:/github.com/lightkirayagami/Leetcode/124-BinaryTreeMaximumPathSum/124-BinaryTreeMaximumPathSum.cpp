// Last updated: 27/04/2026, 21:51:01
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
    int max1=INT_MIN;
    int maxPathSum(TreeNode* root) {

        int a=solve(root);
        return max1;


        
    }

    int solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int a=solve(root->left);
        if(a<0)
        {
            a=0;
        }
        int b=solve(root->right);
        if(b<0)
        {
            b=0;
        }

        int x=max(a,b);

        max1=max(a+b+root->val,max1); //taking max of the path through that root
    

        return x+root->val;//finding best bath possible path

        


    }

    // the main theory is 

//     root
//     /  \.           ===best path (this is our answer)(It can come anytime so we need to keep track of it)
//    /    \
// (max_value) (max_value_from_a_single_path)

// max_value_from_a_single_path==retutn max(a,b)+val

// if any sinle path gices a negative answer we dont need it we make it 0   
};