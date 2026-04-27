// Last updated: 27/04/2026, 21:49:49
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int>>minh;

        for(int i=0;i<nums.size();i++)
        {
            minh.push(nums[i]);

            while(minh.size()>k)
            {
                minh.pop();
            }
        }

        int ans=0;
        return minh.top();

        
    }
};