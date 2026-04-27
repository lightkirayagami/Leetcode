// Last updated: 27/04/2026, 21:48:51
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>maxHeap;


        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        for(auto &it:mp)
        {
            int ele=it.first;
            int freq=it.second;
            maxHeap.push({freq,ele});
        }

        vector<int>ans;

        while(k>0)
        {
            pair<int,int>p=maxHeap.top();
            ans.push_back(p.second);
            maxHeap.pop();
            k--;
        }
        return ans;
        
    }
};