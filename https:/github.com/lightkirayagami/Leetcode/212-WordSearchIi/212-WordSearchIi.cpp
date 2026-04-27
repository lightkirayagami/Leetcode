// Last updated: 27/04/2026, 21:49:52
class Solution {
public:

    vector<string> ans;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    struct trieNode {
        bool end;
        string word;
        trieNode* children[26];

        trieNode() {
            end = false;
            word = "";
            for(int i=0;i<26;i++) children[i]=NULL;
        }
    };

    // insert a word in Trie
    void insertWord(trieNode* root , string &w){
        trieNode* cur = root;
        for(int i=0;i<w.size();i++){
            int idx = w[i]-'a';
            if(cur->children[idx]==NULL)
                cur->children[idx]=new trieNode();
            cur = cur->children[idx];
        }
        cur->end=true;
        cur->word=w;
    }

    // DFS on board using Trie
    void dfs(vector<vector<char>> &board , int i, int j , trieNode* root){
        
        // boundary
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return;

        char ch = board[i][j];

        // visited or not present in trie
        if(ch=='$' || root->children[ch-'a']==NULL)
            return;

        root=root->children[ch-'a'];

        // if a word completes
        if(root->end==true){
            ans.push_back(root->word);
            root->end=false;     // avoid duplicates
        }

        board[i][j]='$';          // mark visited

        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            dfs(board,ni,nj,root);
        }

        board[i][j]=ch;            // backtrack
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        trieNode* root = new trieNode();

        // Build Trie
        for(int i=0;i<words.size();i++)
            insertWord(root,words[i]);

        int m=board.size();
        int n=board[0].size();

        // Try DFS from every cell
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root);
            }
        }

        return ans;
    }
};
