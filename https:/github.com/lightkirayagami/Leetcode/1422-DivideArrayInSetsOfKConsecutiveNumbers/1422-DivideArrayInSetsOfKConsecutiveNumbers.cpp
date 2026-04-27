// Last updated: 27/04/2026, 21:45:51
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }



        while(!mp.empty())
        {
            int smallest=mp.begin()->first;
            mp[smallest]--;
            if(mp[smallest]==0)
            {
                mp.erase(smallest);
            }


            for(int i=smallest+1;i<smallest+k;i++)
            {
                if(mp.find(i)==mp.end())
                {
                    return false;
                }


                mp[i]--;
                if(mp[i]==0)
                {
                    mp.erase(i);
                }
            }

        }
        return true;
    }
};