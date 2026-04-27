// Last updated: 27/04/2026, 21:52:27
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string s1 = s ;
            sort(s1.begin(), s1.end());

            mp[s1].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& sts : mp) {

            ans.push_back(sts.second);
        }
        return ans;
    }
};