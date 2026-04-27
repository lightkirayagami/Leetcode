// Last updated: 27/04/2026, 21:50:58
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> st;
        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }
        queue<string> q;
        q.push(beginWord);
        set<string> ispresent;
        int level = 1;
        ispresent.insert(beginWord);
        while (!q.empty()) {

            int size = q.size();
            while (size--) {
                string f = q.front();
                q.pop();
                vector<string> all = findall(f);

                if (f == endWord) {
                    return level;
                }
                for (int i = 0; i < all.size(); i++) {
                    if (st.find(all[i]) != st.end() &&
                        ispresent.find(all[i]) == ispresent.end()) {
                        q.push(all[i]);
                        ispresent.insert(all[i]);
                        
                    }
                }
            }
            level++;
        }
        return 0;
    }

    vector<string> findall(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                string s1 = s;
                char x = 'a';
                x = x + j;
                s1[i] = x;
                ans.push_back(s1);
            }
        }
        return ans;
    }
};