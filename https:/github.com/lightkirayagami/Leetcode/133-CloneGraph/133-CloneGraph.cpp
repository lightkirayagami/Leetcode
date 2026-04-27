// Last updated: 27/04/2026, 21:50:50
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        queue<Node*>q;
        if(node == NULL) return NULL;
        q.push(node);
        Node* newNode=new Node();
        newNode->val=node->val;
        map<Node*,Node*>mp;
        mp.insert({node,newNode});

        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();

            for(auto &ngh:front->neighbors)
            {
                if(mp.find(ngh)==mp.end())
                {
                    Node* newNode=new Node();
                    newNode->val=ngh->val;
                    mp.insert({ngh,newNode});
                  mp[front]->neighbors.push_back(mp[ngh]);
                    q.push(ngh);
                }
                else
                {
                    mp[front]->neighbors.push_back(mp[ngh]);
                }
            }
            


        }
        return newNode;
        
    }
};