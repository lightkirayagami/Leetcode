// Last updated: 27/04/2026, 21:46:51
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        getParents(root,mp,NULL);
        vector<int>ans;
        set<TreeNode*>visited;
        nodeAtDistanceK(target,k,mp,ans,visited);
            return ans;
        
        
        
    }
    
    void nodeAtDistanceK(TreeNode* current , int k , map<TreeNode*,TreeNode*>&mp , vector<int>&ans , set<TreeNode*>visited )
    {
        if(current==NULL|| visited.find(current)!=visited.end())
        {
            return;
            
        }
       
        
        if(k==0)
        {
            ans.push_back(current->val);
            return;
        }
         visited.insert(current);
        nodeAtDistanceK(current->left,k-1,mp,ans,visited);
        nodeAtDistanceK(current->right,k-1,mp,ans,visited);
        nodeAtDistanceK(mp[current],k-1,mp,ans,visited);
        return;
        
        
    }
    void getParents(TreeNode* root , map<TreeNode* , TreeNode*>&mp , TreeNode* parent )
    {
        if(root==NULL)
        {
            return ;
        }
        mp[root]=parent;
        getParents(root->left,mp,root);
        getParents(root->right,mp,root);
        return;
        
    }
        
};