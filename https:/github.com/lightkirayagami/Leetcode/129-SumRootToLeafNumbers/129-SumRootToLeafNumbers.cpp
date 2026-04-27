// Last updated: 27/04/2026, 21:50:55
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
    int sumNumbers(TreeNode* root) {


        vector<string>ans;

        solve(root,"",ans);

        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
        int sum=0;

        for(int i=0;i<ans.size();i++)
        {
            int x=stoi(ans[i]);
            sum=sum+x;
           
        }
        return sum;

        
    }

    void solve(TreeNode* root,string s,vector<string>&ans)
    
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            char c=root->val+'0';
            string s1=s+c;
            ans.push_back(s1);
        }

        

        char c=root->val+'0';

        solve(root->left,s+c,ans);
        solve(root->right,s+c,ans);


    }
};