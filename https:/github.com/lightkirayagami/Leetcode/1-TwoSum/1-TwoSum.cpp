// Last updated: 27/04/2026, 21:53:21
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int>ans;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {


            auto it=mp.find(target-nums[i]);
            if(it!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(it->second);
            }

            mp.insert({nums[i],i});
        }
        return ans;
        
    }
};