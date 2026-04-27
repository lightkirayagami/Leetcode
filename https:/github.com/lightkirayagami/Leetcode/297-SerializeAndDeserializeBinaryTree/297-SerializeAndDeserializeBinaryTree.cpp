// Last updated: 27/04/2026, 21:49:10
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
     string serialize(TreeNode* root) {
        if(root == NULL) return "";

        queue<TreeNode*> q;
        q.push(root);

        string res = "";

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if(cur == NULL) {
                res += "N,";
                continue;
            }

            res += to_string(cur->val);
            res += ",";

            q.push(cur->left);
            q.push(cur->right);
        }

        return res;
    }

    // reads next token until comma and moves index forward
    string nextToken(string &data, int &i) {
        string tok = "";
        while(i < data.size() && data[i] != ',') {
            tok.push_back(data[i]);
            i++;
        }
        i++; // skip comma
        return tok;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        int i = 0;
        string first = nextToken(data, i);
        if(first == "N") return NULL;

        TreeNode* root = new TreeNode(stoi(first));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if(i >= data.size()) break;

            // left
            string L = nextToken(data, i);
            if(L != "N") {
                cur->left = new TreeNode(stoi(L));
                q.push(cur->left);
            }

            if(i >= data.size()) break;

            // right
            string R = nextToken(data, i);
            if(R != "N") {
                cur->right = new TreeNode(stoi(R));
                q.push(cur->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));