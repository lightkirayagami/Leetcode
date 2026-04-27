// Last updated: 27/04/2026, 21:44:47
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        map<int,vector<int>>mp;
        vector<long long>ans(nums.size(),0);

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }


        for(auto &it:mp)
        {
            int value=it.first;
            vector<int>&v=it.second;

            long long totalsum=0;
            for(int i=0;i<v.size();i++)
            {
                totalsum=totalsum+v[i];
            }
            long long leftsum=0;

            for(int i=0;i<v.size();i++)
            {
                int curr=v[i];
                long long rightsum=totalsum-leftsum-curr;

                long long left=(long long)i*curr-leftsum;
                long long right=rightsum-(long long)(v.size()-i-1)*curr;

                ans[curr]=left+right;
                leftsum=leftsum+curr;
            }



        }

        return ans;
        
    }
};