// Last updated: 27/04/2026, 21:49:57
class Trie {
public:

struct trieNode{
    bool end;
    trieNode* children[26];

    trieNode()
    {
        end=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};

trieNode* root;

    Trie() {

    root=new trieNode();
        
    }
    
    void insert(string word) {

        trieNode* curr=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i]-'a';
            if(curr->children[idx]==NULL)
            {
                curr->children[idx]=new trieNode;
            }
            curr=curr->children[idx];
        }

        curr->end=true;
        
    }
    
    bool search(string word) {

        trieNode* curr=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i]-'a';
            if(curr->children[idx]==NULL)
            {
                return false;
            }
            curr=curr->children[idx];
        }

        if(curr->end==true)
        return true;

        return false;

        
        
    }
    
    bool startsWith(string prefix) {

         trieNode* curr=root;
        for(int i=0;i<prefix.size();i++)
        {
            int idx=prefix[i]-'a';
            if(curr->children[idx]==NULL)
            {
                return false;
            }
            curr=curr->children[idx];
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */