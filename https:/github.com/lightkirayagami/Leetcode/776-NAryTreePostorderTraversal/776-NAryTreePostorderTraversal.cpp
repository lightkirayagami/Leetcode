// Last updated: 27/04/2026, 21:47:07
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
    vector<int> postorder(Node* root) {
          vector<int> post;
        solve(root, post);
        return post;
        
    }
    void solve(Node* root, vector<int> &post) {
        if(root == nullptr) return;
        
        for(auto node: root->children) {
            solve(node, post);
        }
        
        post.push_back(root->val);
    }
};