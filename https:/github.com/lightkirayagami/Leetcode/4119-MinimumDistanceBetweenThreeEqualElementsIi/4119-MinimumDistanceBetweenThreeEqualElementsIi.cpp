// Last updated: 27/04/2026, 21:44:34
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto it : mp) {

            vector<int> temp = it.second;

              if(temp.size() < 3) continue;

            for(int i = 0; i  < temp.size()-2; i++) {
                int x = temp[i];
                int z = temp[i+2];

                ans = min(ans, 2 * (z - x));
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
        
    }
};