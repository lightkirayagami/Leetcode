// Last updated: 27/04/2026, 21:47:11
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        for(Node* const &it:root->children)
        {
            ans=max(ans,maxDepth(it));
        }
        return 1+ans;
    }
};