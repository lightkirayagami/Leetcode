// Last updated: 27/04/2026, 21:53:08
class Solution {
public:
    struct trieNode {

        trieNode* child[26];
        bool endofword;
        int noofcon;

        trieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            endofword = false;
            noofcon = 0;
        }
    };

    void insert(trieNode* root, string& s) {

        trieNode* curr = root;

        for (auto& c : s) {
            if (curr->child[c - 'a'] == NULL) {
                curr->child[c - 'a'] = new trieNode();
                curr->noofcon++;
            }

            curr = curr->child[c - 'a'];
        }

        curr->endofword = true;
    }
    string longestCommonPrefix(vector<string>& strs) {

        trieNode* root = new trieNode();

        for (auto& s : strs) {
            insert(root, s);
        }

        trieNode* curr = root;

        string key = strs[0];
        string ans = "";

        for (auto& c : key) {
            if (curr->noofcon == 1 && curr->endofword == false) {
                ans.push_back(c);
                curr = curr->child[c - 'a'];
            } else {
                break;
            }
        }
        return ans;
    }
};