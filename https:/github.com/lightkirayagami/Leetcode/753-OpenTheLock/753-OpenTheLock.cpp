// Last updated: 27/04/2026, 21:47:16
class Solution {
public:
    vector<string> getNext(string s) {
        vector<string> res;

        for (int i = 0; i < 4; i++) {
            string up = s;
            string down = s;

            // move digit up
            up[i] = (s[i] == '9') ? '0' : s[i] + 1;

            // move digit down
            down[i] = (s[i] == '0') ? '9' : s[i] - 1;

            res.push_back(up);
            res.push_back(down);
        }

        return res;
    }
    int openLock(vector<string>& deadends, string target) {

        

        set<string> dead;
        for (int i = 0; i < deadends.size(); i++) {
            dead.insert(deadends[i]);
        }
        set<string> ispresent;

        if(dead.find("0000")!=dead.end())
        {
            return -1;
        }

        queue<string> q;
        ispresent.insert("0000");
        q.push("0000");
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    return ans;
                }
                vector<string> pans = getNext(p);
                for (int i = 0; i < pans.size(); i++) {
                    string s = pans[i];
                    if (ispresent.find(s) == ispresent.end() &&
                        dead.find(s) == dead.end()) {
                        ispresent.insert(s);
                        q.push(s);
                        
                    }
                }
            }

            ans = ans + 1;
        }
        return -1;
    }
};
