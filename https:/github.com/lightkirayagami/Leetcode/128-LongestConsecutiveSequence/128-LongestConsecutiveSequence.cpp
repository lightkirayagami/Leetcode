// Last updated: 27/04/2026, 21:50:57
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>m;
        
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            m.insert(nums[i]);
        }
        int maxlen=1;
        for(int i=0;i<n;i++)
        {
            int l=1;
            int ele=nums[i];
            if(m.find(ele-1)!=m.end())
            {
                continue;
            }
            while(m.find(ele+1)!=m.end()){
                ele++;
                l++;

            }
            maxlen=max(l,maxlen);
            
            

        }
        return maxlen;

        
    }
};