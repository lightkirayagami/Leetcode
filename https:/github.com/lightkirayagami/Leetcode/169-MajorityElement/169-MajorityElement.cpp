// Last updated: 27/04/2026, 21:50:22
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ele=-1;
        int times=-1;
        for(auto &it:m)
        {
            if(it.second>times)
            {
                ele=it.first;
                times=it.second;
            }
        }
        return ele;
        
    }
};