// Last updated: 27/04/2026, 21:53:07
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        map<vector<int>, int> mp;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;
             
            while(j<k)
            {
            if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            } else if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            } else {
               
               ans.push_back({nums[i],nums[j],nums[k]});
               while(j<k&&nums[j]==nums[j+1])j++;
               while(j<k&&nums[k]==nums[k-1])k--;

               j++;
               k--;
            }
            }
        }
        return ans;
    }
};