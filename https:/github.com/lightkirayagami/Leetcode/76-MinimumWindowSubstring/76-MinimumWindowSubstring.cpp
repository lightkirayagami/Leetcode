// Last updated: 27/04/2026, 21:51:56
class Solution {
public:
    string minWindow(string s, string t) {

        int haveCount = 0;
        int reqCount = 0;
        vector<int> have(128, 0);
        vector<int> req(128, 0);
        int best_start = 0;

        int i = 0;
        int j = 0;
        int n = s.size();

        for (int i = 0; i < t.size(); i++) {
            req[(int)t[i]]++;
        }

        for (int i = 0; i < 128; i++) {
            if (req[i] > 0) {
                reqCount++;
            }
        }
        int ans = INT_MAX;

        while (j < n) {
            while (haveCount < reqCount && j < n) {

                if ((int)req[s[j]] > 0) {
                    have[(int)s[j]]++;
                }

                if (req[s[j]] > 0 && have[(int)s[j]] == req[(int)s[j]]) {
                    haveCount++;
                }

                if (haveCount == reqCount && ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    best_start = i;
                }
                j++;
            }

            while (haveCount == reqCount) {

                
                if (haveCount == reqCount && ans > j - i ) {
                    ans = min(ans, j - i );
                    best_start = i;
                }

                if (req[s[i]] > 0) {
                    have[s[i]]--;
                    if (have[s[i]] < req[s[i]])
                        haveCount--;
                }

         

                

                i++;
            }
        }
        if (ans == INT_MAX)
            return "";
        return s.substr(best_start, ans);
    }
};