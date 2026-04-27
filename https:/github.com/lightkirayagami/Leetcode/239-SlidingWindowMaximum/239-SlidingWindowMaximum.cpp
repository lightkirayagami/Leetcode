// Last updated: 27/04/2026, 21:49:27
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int i=0;
        deque<int>dq;
        vector<int>ans;

        for(int j=0;j<nums.size();j++)
        {
            while(!dq.empty()&&nums[j]>dq.back())
            {
                dq.pop_back();
            }

            dq.push_back(nums[j]);

            if(j-i+1>k)
            {
                if(nums[i]==dq.front())
                {
                    dq.pop_front();
                }
                i++;
            }
            if(j-i+1==k)
            {
                ans.push_back(dq.front());
            }


        }
        return ans;
        
    }
};